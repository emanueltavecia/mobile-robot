#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper motor1(stepsPerRevolution, 2, 3);
Stepper motor2(stepsPerRevolution, 4, 5);

String userInput;
char codeLetter;
int timeSpinning;
int leftWheelSpeed;
int rightWheelSpeed;

void setup() {
  motor1.setSpeed(leftWheelSpeed);
  motor2.setSpeed(rightWheelSpeed);
  Serial.begin(9600);
}

void loop() {  
  prompt();

  if (codeLetter == 'F') {
    if (leftWheelSpeed >= 1 && leftWheelSpeed <= 5 && rightWheelSpeed >= 1 && rightWheelSpeed <= 5) {
      forward();
    } else {
      Serial.println("Invalid speed. Minimum value: 1. Maximum value: 5.");
    }
  }

  else if (codeLetter == 'B') {
    if (leftWheelSpeed >= 1 && leftWheelSpeed <= 5 && rightWheelSpeed >= 1 && rightWheelSpeed <= 5) {
      backward();
    } else {
      Serial.println("Invalid speed. Minimum value: 1. Maximum value: 5.");
    }
  }

  else if (codeLetter == 'H') {
    help();
  }
  
  else {
    Serial.println("Invalid code. Type h to help.");
  }
}

void prompt() {
  timeSpinning = NULL;
  leftWheelSpeed = NULL;
  rightWheelSpeed = NULL;
  
  Serial.println("Enter a code (options: f (forward), b (backward), h (help):");
  
  while (Serial.available() == 0) {}
  
  userInput = Serial.readStringUntil('\n');

  codeLetter = toupper(userInput.charAt(0));

  char* token = strtok((char*)userInput.c_str() + 2, ",");
  timeSpinning = atoi(token) * 1000;
  token = strtok(NULL, ",");
  leftWheelSpeed = atoi(token);
  token = strtok(NULL, ",");
  rightWheelSpeed = atoi(token);
}

void forward() {
  unsigned long startTime = millis();
  if (timeSpinning != NULL && leftWheelSpeed != NULL && rightWheelSpeed != NULL) {
    setSpeed();
    while (millis() - startTime < timeSpinning) {
      motor1.step(1);
      motor2.step(1);
    }
  }
  else {
    Serial.println("Invalid code. Type h to help.");
  }
}

void backward() {
  unsigned long startTime = millis();
  if (timeSpinning != NULL && leftWheelSpeed != NULL && rightWheelSpeed != NULL) {
    setSpeed();
    while (millis() - startTime < timeSpinning) {
      motor1.step(-1);
      motor2.step(-1);
    }
  }
  else {
    Serial.println("Invalid code. Type h to help.");
  }
}

void help() {
  Serial.println("HELP");
  Serial.println("F - forward");
  Serial.println("B - Backward");
  Serial.println("Template: F,1,2,3");
  Serial.println("1 - 1 second");
  Serial.println("2 - left wheel speed");
  Serial.println("3 - right wheel speed");
  Serial.println("Possible speed values: 1, 2, 3, 4, 5");
}

void setSpeed() {
  if (leftWheelSpeed >= 1 && leftWheelSpeed <= 5) {
    switch (leftWheelSpeed) {
      case 1:
        leftWheelSpeed = 500;
        break;
      case 2:
        leftWheelSpeed = 600;
        break;
      case 3:
        leftWheelSpeed = 700;
        break;
      case 4:
        leftWheelSpeed = 800;
        break;
      case 5:
        leftWheelSpeed = 1000;
        break;
    }
    Serial.println("Current left speed: " + String(leftWheelSpeed) + " rpm");
  }

  if (rightWheelSpeed >= 1 && rightWheelSpeed <= 5) {
    switch (rightWheelSpeed) {
      case 1:
        rightWheelSpeed = 500;
        break;
      case 2:
        rightWheelSpeed = 600;
        break;
      case 3:
        rightWheelSpeed = 700;
        break;
      case 4:
        rightWheelSpeed = 800;
        break;
      case 5:
        rightWheelSpeed = 1000;
        break;
    }
    Serial.println("Current right speed: " + String(rightWheelSpeed) + " rpm");
  }
}
