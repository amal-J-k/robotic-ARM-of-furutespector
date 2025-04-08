#include <Servo.h>

// Define servo objects
Servo servo01; // Base rotation
Servo servo02; // Shoulder
Servo servo03; // Elbow

// Define pin numbers
#define BASE_PIN 5
#define SHOULDER_PIN 6
#define ELBOW_PIN 7

// Current positions of the servos
int servo01Pos = 180; // Initial position for servo 01 (base)
int servo02Pos = 100; // Initial position for servo 02 (shoulder)
int servo03Pos = 35;  // Initial position for servo 03 (elbow)

//// Define positions for movements
//int homePosition[3] = {180, 100, 35}; // Home position
//int pickPosition[3] = {90, 45, 30};   // Position to pick the apple
//int dropPosition[3] = {90, 90, 30};   // Position to drop the apple

void setup() {
  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  
  
  // Set initial positions
  servo01Pos = 90;  // Base
  servo01.write(servo01Pos);
  servo02Pos = 150; // Shoulder
  servo02.write(servo02Pos);
  servo03Pos = 35;  // Elbow
  servo03.write(servo03Pos);

}


void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Read the incoming command
    processCommand(command); // Process the command
  }
}

void processCommand(String command) {
  // Split the command into parts
  int separatorIndex = command.indexOf(',');
  if (separatorIndex == -1) {
    Serial.println("Invalid command format. Use: servoID,position");
    return;
  }

  String servoID = command.substring(0, separatorIndex);
  int position = command.substring(separatorIndex + 1).toInt(); // Convert to integer

  // Check if the position is within the valid range
  if (position < 0 || position > 180) {
    Serial.println("Invalid position. Please send a value between 0 and 180.");
    return;
  }

  // Move the specified servo only if the command is valid
  if (servoID == "base") {
    servo01.write(position);
    servo01Pos = position; // Update current position
    Serial.print("Base moved to: ");
    Serial.println(position);
  } else if (servoID == "shoulder") {
    servo02.write(position);
    servo02Pos = position; // Update current position
    Serial.print("Shoulder moved to: ");
    Serial.println(position);
  } else if (servoID == "elbow") {
    servo03.write(position);
    servo03Pos = position; // Update current position
    Serial.print("Elbow moved to: ");
    Serial.println(position);
  } else {
    Serial.println("Invalid servo ID. Use 'base', 'shoulder', or 'elbow'.");
  }
}

void moveToPosition(int positions[3]) {
  servo01.write(positions[0]);
  servo02.write(positions[1]);
  servo03.write(positions[2]);
  delay(1000); // Allow time for the servos to reach the position
}
