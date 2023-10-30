#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper motor1(stepsPerRevolution, 2, 3);
Stepper motor2(stepsPerRevolution, 4, 5);

const int radius = 34;
const int b = 250;
float rightWheelSpeed;
float leftWheelSpeed;

String userInput;
char codeLetter;
int linear;
int angular;

int currentVelocity = 300;

void setup() {
  motor1.setSpeed(500);
  motor2.setSpeed(500);
  Serial.begin(9600);
}

void loop() {
  linear = 0;
  angular = 0;

  Serial.println("Enter a code (options: v, f, b):");
  
  while (Serial.available() == 0) {}

  userInput = Serial.readString();

  userInput.toUpperCase();

  char *str = (char *)userInput.c_str();
  char *token = strtok(str, ",");
  
  if (token != NULL) {
    codeLetter = token[0];
    token = strtok(NULL, ",");
    if (token != NULL) {
      linear = atoi(token);
      token = strtok(NULL, ",");
      if (token != NULL) {
        angular = atoi(token);
      }
    }
  }

  if (codeLetter == 'V') {
    if (angular == 0) {
      motor1.setSpeed(linear * 9.549);
      motor2.setSpeed(linear * 9.549);
    } else {
      rightWheelSpeed = (linear / b) + ((b / (2 * radius)) * angular);
      leftWheelSpeed = (linear / b) - ((b / (2 * radius)) * angular);

      motor1.setSpeed(rightWheelSpeed * 9.549);
      motor2.setSpeed(leftWheelSpeed * 9.549);
    }
  } else if (codeLetter == 'F') {
    for(int i = 0; i < linear; i++) {
      for(int i = 0; i < 800; i++) {
        motor1.step(1);
        motor2.step(1);
      }
        Serial.println("step");
    }
  } else if (codeLetter == 'B') {
    for(int i = 0; i < linear; i++) {
      for(int i = 0; i < 800; i++) {
        motor1.step(-1);
        motor2.step(-1);
      }
        Serial.println("step");
    }
  } else {
    Serial.println("Invalid code.");
  }
}
