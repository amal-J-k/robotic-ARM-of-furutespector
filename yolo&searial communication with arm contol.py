import cv2
import serial
import time
from ultralytics import YOLO

# Load the custom-trained model
model = YOLO("/home/unix/AI ML/best.pt")

# Set up the serial connection (adjust '/dev/ttyUSB0' as needed)
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)  # Use the correct port for your setup
time.sleep(2)  # Wait for the connection to establish

# Open the video stream from the IP Webcam Pro app
cap = cv2.VideoCapture('http://192.168.4.186:8080/video')

# Initialize counters
total_apples_detected = 0
bad_apples_detected = 0
good_apples_detected = 0
picked_apples = 0

try:
    while True:
        # Read a frame from the video stream
        ret, frame = cap.read()
        
        if not ret:
            break
        
        # Convert the frame to a numpy array
        img = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        
        # Run the model on the frame
        results = model(img)
        
        # Draw the bounding boxes on the image
        bad_apple_detected = False  # Flag to check if a bad apple is detected
        for result in results:
            # Access the boxes and their attributes
            boxes = result.boxes
            for box in boxes:
                # Get the bounding box coordinates and class index
                x1, y1, x2, y2 = box.xyxy[0].tolist()  # Get bounding box coordinates
                class_id = int(box.cls[0])  # Get the class index
                confidence = box.conf[0].item()  # Get the confidence score

                # Check if the confidence is above 80%
                if confidence >= 0.80:  # Confidence threshold
                    total_apples_detected += 1  # Increment total apples detected
                    # Check if it's a "bad apple"
                    if class_id == 1:  
                        bad_apples_detected += 1  # Increment bad apples detected
                        bad_apple_detected = True
                        cv2.rectangle(frame, (int(x1), int(y1)), (int(x2), int(y2)), (0, 0, 255), 2)  # Red box for bad apple
                    else:
                        good_apples_detected += 1  # Increment good apples detected
                        cv2.rectangle(frame, (int(x1), int(y1)), (int(x2), int(y2)), (0, 255, 0), 2)  # Green box for good apple
        
        # If a bad apple is detected, send commands to Arduino to control the arm
        if bad_apple_detected:
            picked_apples += 1  # Increment picked apples count
            # Move to the pick position
            ser.write("s1,80\n".encode('utf-8'))      # Adjust base to 80 degrees
            ser.write("s2,50\n".encode('utf-8'))      # Adjust shoulder to 50 degrees
            ser.write("s3,25\n".encode('utf-8'))      # Adjust elbow to 25 degrees
            time.sleep(2)  # Wait for the arm to reach the pick position
            
            # Simulate picking action
            print("Picking the bad apple...")
            time.sleep(1)  # Simulate time taken to pick
            
            # Move to the drop position
            ser.write("s1,80\n".encode('utf-8'))      # Keep base at 80 degrees
            ser.write("s2,90\n".encode('utf-8'))      # Adjust shoulder to 90 degrees
            ser.write("s3,30\n".encode('utf-8'))      # Adjust elbow to 30 degrees
            time.sleep(2)  # Wait for the arm to reach the drop position
            
            # Simulate dropping action
            print("Dropping the bad apple...")
            time.sleep(1)  # Simulate time taken to drop
            
            # Return to home position
            ser.write("s1,90\n".encode('utf-8'))      # Move base back to 90 degrees
            ser.write("s2,150\n".encode('utf-8'))     # Move shoulder back to 150 degrees
            ser.write("s3,35\n".encode('utf-8'))      # Move elbow
            ser.write("s3,35\n".encode('utf-8'))      # Move elbow back to 35 degrees
            time.sleep(2)  # Wait for the arm to return to home position


        
        # Display the frame with the bounding boxes
        cv2.imshow('Frame', frame)
        
        # Exit on key press
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

except KeyboardInterrupt:
    print("Exiting...")
finally:
    # Release the video capture and close the serial connection
    cap.release()
    ser.close()
    cv2.destroyAllWindows()

    # Print the total counts
    print(f"Total apples detected: {total_apples_detected}")
    print(f"Number of bad apples detected: {bad_apples_detected}")
    print(f"Number of good apples detected: {good_apples_detected}")
    print(f"Number of picked apples: {picked_apples}")
