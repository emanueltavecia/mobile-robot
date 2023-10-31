#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper motor1(stepsPerRevolution, 2, 3);
Stepper motor2(stepsPerRevolution, 4, 5);

String userInput;
char codeLetter;
int timeSpinning;
int leftWheelSpeed;
int rightWheelSpeed;

int currentVelocity = 300;

void setup() {
  motor1.setSpeed(500);
  motor2.setSpeed(500);
  Serial.begin(9600);
}

void loop() {  
  prompt();

  if (codeLetter == 'F') {
    forward();
  }

  else if (codeLetter == 'B') {
    backward();
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
    while (millis() - startTime < timeSpinning) {
      Serial.println("Hello, World. Forwarding.");
      delay(1000);
    }
  }
  else {
    Serial.println("Invalid code. Type h to help.");
  }
}

void backward() {
  unsigned long startTime = millis();
  if (timeSpinning != NULL && leftWheelSpeed != NULL && rightWheelSpeed != NULL) {
    while (millis() - startTime < timeSpinning) {
      Serial.println("Hello, World. Backwarding.");
      delay(1000);
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