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
int servo01Pos = 180; // Initial position for servo 01
int servo02Pos = 90; // Initial position for servo 02
int servo03Pos = 90; // Initial position for servo 03
int pos = 90;

void setup() {
  // Attach the servos to the appropriate pins
  servo01.attach(BASE_PIN);
  servo02.attach(SHOULDER_PIN);
  servo03.attach(ELBOW_PIN);


//  // Set initial positions
//  servo01.write(servo01Pos);
//  servo02.write(servo02Pos);
//  servo03.write(servo03Pos);
  
  
  delay(1000); // Allow servos to reach initial position
}
void loop() {
  // Move shoulder from 90 degrees to 120 degrees
  for (float pos = 0; pos <= 120; pos += 0.5) { // goes from 90 degrees to 120 degrees
    servo02.write((int)pos);              // tell servo to go to position in variable 'pos'
    delay(30);                            // waits 30ms for the servo to reach the position
  }

  // Move shoulder from 120 degrees back to 90 degrees
  for (float pos = 0; pos >= 90; pos -= 0.5) { // goes from 120 degrees back to 90 degrees
    servo02.write((int)pos);              // tell servo to go to position in variable 'pos'
    delay(30);                            // waits 30ms for the servo to reach the position
  }
}


//void loop() {
  // Example movements
 
//  moveShoulder(0); // Move shoulder to 150 degrees
//  delay(1000);
//  delay(1000);

//
// moveBase(0); // Move base to 0 degrees
//  delay(1000);
//  moveBase(180); // Move base to 180 degrees
//  delay(1000);
//
//  
//  moveElbow(150); // Move elbow to 90 degrees
//  delay(1000);
//  delay(1000);
//  
  

  
//  moveShoulder(0); // Move shoulder to 90 degrees
//  delay(1000);
//  delay(1000);
  
  
 
  
 

//   
//  moveElbow(0); // Move elbow to 30 degrees
//  delay(1000);
//  delay(1000);
//  
  
 
  
//}

//void moveBase(int position) {
//  servo01Pos = position;
//  servo01.write(servo01Pos);
//  delay(2000 ); // Delay for smooth movement
//}

//void moveShoulder(int position) {
//  servo02Pos = position;
//  servo02.write(servo02Pos);
//  delay(1000);
//}

//void moveElbow(int position) {
//  servo03Pos = position;
//  servo03.write(servo03Pos);
//  delay(2000);
//}
//
