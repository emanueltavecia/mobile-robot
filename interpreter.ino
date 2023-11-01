#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper motor1(stepsPerRevolution, 2, 3);
Stepper motor2(stepsPerRevolution, 4, 5);

String userInput;
char codeLetter;
int timeSpinning;
int wheelSpeed;

void setup() {
  motor1.setSpeed(wheelSpeed);
  motor2.setSpeed(wheelSpeed);
  Serial.begin(9600);
}

void loop() {  
  prompt();

  if (codeLetter == 'F') {
    if (wheelSpeed >= 1 && wheelSpeed <= 5) {
      forward();
    } else {
      Serial.println("Invalid speed. Minimum value: 1. Maximum value: 5.");
    }
  }

  else if (codeLetter == 'B') {
    if (wheelSpeed >= 1 && wheelSpeed <= 5) {
      backward();
    } else {
      Serial.println("Invalid speed. Minimum value: 1. Maximum value: 5.");
    }
  }

  else if (codeLetter == 'L') {
    if (wheelSpeed >= 1 && wheelSpeed <= 5) {
      turnLeft();
    } else {
      Serial.println("Invalid speed. Minimum value: 1. Maximum value: 5.");
    }
  }

  else if (codeLetter == 'R') {
    if (wheelSpeed >= 1 && wheelSpeed <= 5) {
      turnRight();
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
  wheelSpeed = NULL;
  
  Serial.println("Enter a code (options: F (forward), B (backward), L (turn left), R (turn right), H (help):");
  
  while (Serial.available() == 0) {}
  
  userInput = Serial.readStringUntil('\n');

  codeLetter = toupper(userInput.charAt(0));

  char* token = strtok((char*)userInput.c_str() + 2, ",");
  timeSpinning = atoi(token) * 1000;
  token = strtok(NULL, ",");
  wheelSpeed = atoi(token);
}

void forward() {
  unsigned long startTime = millis();
  if (timeSpinning != NULL && wheelSpeed != NULL) {
    setSpeed();
    while (millis() - startTime < timeSpinning) {
      motor1.step(-1);
      motor2.step(1);
    }
  }
  else {
    Serial.println("Invalid code. Type h to help.");
  }
}

void backward() {
  unsigned long startTime = millis();
  if (timeSpinning != NULL && wheelSpeed != NULL) {
    setSpeed();
    while (millis() - startTime < timeSpinning) {
      motor1.step(1);
      motor2.step(-1);
    }
  }
  else {
    Serial.println("Invalid code. Type h to help.");
  }
}

void turnLeft() {
  unsigned long startTime = millis();
  if (timeSpinning != NULL && wheelSpeed != NULL) {
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

void turnRight() {
  unsigned long startTime = millis();
  if (timeSpinning != NULL && wheelSpeed != NULL) {
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
  Serial.println("----HELP----");
  Serial.println("F - forward");
  Serial.println("B - Backward");
  Serial.println("L - Turn Left");
  Serial.println("R - Turn Right");
  Serial.println("Template: F,1,2");
  Serial.println("1 - 1 second");
  Serial.println("2 - wheel speed");
  Serial.println("Possible speed values: 1, 2, 3, 4, 5");
}

void setSpeed() {
  if (wheelSpeed >= 1 && wheelSpeed <= 5) {
    switch (wheelSpeed) {
      case 1:
        wheelSpeed = 500;
        break;
      case 2:
        wheelSpeed = 600;
        break;
      case 3:
        wheelSpeed = 700;
        break;
      case 4:
        wheelSpeed = 800;
        break;
      case 5:
        wheelSpeed = 1000;
        break;
    }
    Serial.println("Current speed: " + String(wheelSpeed) + " rpm");
  }
  motor1.setSpeed(wheelSpeed);
  motor2.setSpeed(wheelSpeed);
}
