#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper motor1(stepsPerRevolution, 2, 3);
Stepper motor2(stepsPerRevolution, 4, 5);

String userInput;
char codeLetter;
int codeNumber;

int currentVelocity = 300;

void setup() {
  motor1.setSpeed(500);
  motor2.setSpeed(500);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter a code (options: v, f, b):");
  
  while (Serial.available() == 0) {}

  userInput = Serial.readStringUntil('\n');
  codeLetter = toupper(userInput.charAt(0));
  codeNumber = userInput.substring(1).toInt();

  if (codeLetter == 'V') {
    motor1.setSpeed(codeNumber);
    motor2.setSpeed(codeNumber);
  } else if (codeLetter == 'F') {
    for(int i = 0; i < codeNumber; i++) {
      for(int i = 0; i < 800; i++) {
        motor1.step(1);
        motor2.step(1);
      }
    }
  } else if (codeLetter == 'B') {
    for(int i = 0; i < codeNumber; i++) {
      for(int i = 0; i < 800; i++) {
        motor1.step(-1);
        motor2.step(-1);
      }
    }
  }
}