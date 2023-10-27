const int stepPin1 = 2;
const int dirPin1 = 3;
const int stepPin2 = 4;
const int dirPin2 = 5;

String userInput;
char codeLetter;
int codeNumber;

int currentVelocity = 500;

void setup() {
  pinMode(stepPin1, OUTPUT); 
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT); 
  pinMode(dirPin2, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter a code (options: v, f, b):");

  while (Serial.available() == 0) {}

  userInput = Serial.readStringUntil('\n');
  codeLetter = toupper(userInput.charAt(0));
  codeNumber = userInput.substring(1).toInt();

  if (codeLetter == 'V') {
    setVelocity();
  }
  else if (codeLetter == 'F') {
    for(int i = 0; i < codeNumber; i++) {
      moveForward();
    }
  }
  else if (codeLetter == 'B') {
    for(int i = 0; i < codeNumber; i++) {
      moveBackward();
    }
  }
  else {
    Serial.println("Invalid code.");
  }

  delay(1000);
}

void setVelocity() {
  if (codeNumber >= 1 && codeNumber <= 5) {
    switch (codeNumber) {
      case 1:
        currentVelocity = 700;
        break;
      case 2:
        currentVelocity = 600;
        break;
      case 3:
        currentVelocity = 500;
        break;
      case 4:
        currentVelocity = 400;
        break;
      case 5:
        currentVelocity = 300;
        break;
    }
    Serial.println("Current velocity: " + String(codeNumber));
  } else {
    Serial.println("Invalid velocity. Minimum value: 1. Maximum value: 5.");
  }
}

void moveForward() {
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);

  for(int i = 0; i < 200; i++) {
    digitalWrite(stepPin1, HIGH);
    delayMicroseconds(currentVelocity);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(currentVelocity);

    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(currentVelocity);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(currentVelocity);
  }
}

void moveBackward() {
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);

  for(int i = 0; i < 200; i++) {
    digitalWrite(stepPin1, HIGH);
    delayMicroseconds(currentVelocity);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(currentVelocity);

    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(currentVelocity);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(currentVelocity);
  }
}
