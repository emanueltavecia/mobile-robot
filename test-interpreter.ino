#include <Stepper.h>

// Define the number of steps per revolution for your stepper motors
const int stepsPerRevolution = 200; // Change this according to your motor specifications

// Initialize two instances of the Stepper class
Stepper motor1(stepsPerRevolution, 2, 3); // Replace 8 and 9 with your actual pin numbers
Stepper motor2(stepsPerRevolution, 4, 5); // Replace 10 and 11 with your actual pin numbers

void setup() {
  // Set the speed for both motors
  motor1.setSpeed(100); // You can change this value as needed
  motor2.setSpeed(100); // You can change this value as needed
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the command letter
    int value = Serial.parseInt(); // Read the following number

    // Perform actions based on the command
    if (command == 'v') {
      // Set the speed for both motors
      motor1.setSpeed(value);
      motor2.setSpeed(value);
    } else if (command == 'f') {
      // Rotate both motors forward
      motor1.step(stepsPerRevolution * value);
      motor2.step(stepsPerRevolution * value);
    } else if (command == 'b') {
      // Rotate both motors backward
      motor1.step(-stepsPerRevolution * value);
      motor2.step(-stepsPerRevolution * value);
    }
  }
}
