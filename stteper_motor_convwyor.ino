#include <AFMotor.h>

const int steps_per_rev = 100; // Set to 200 for NEMA 17 and set to 48 for 28BYJ-48
const int steps_per_cycle = 2000; // Number of steps for each cycle
const int speed = 100; // Speed of the motor

// Motor connected with port1 (M1 and M2)
AF_Stepper motor(steps_per_rev, 1);

void setup() {
  Serial.begin(115200);
  motor.setSpeed(speed);  // Set the speed for continuous rotation
}

void loop() {
  Serial.println("Continuous rotation in one direction");
  
  // Rotate continuously in one direction
  motor.step(steps_per_cycle, FORWARD, SINGLE); // Adjust the number of steps as needed
  delay(1); // Short delay to allow for continuous movement
}
