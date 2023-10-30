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

  static unsigned long tempoAnterior = 0;
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= 1000) {
    // A cada segundo, imprime o tempo decorrido em segundos
    Serial.print("Tempo decorrido: ");
    Serial.print(tempoAtual / 1000); // Converter para segundos
    Serial.println(" segundos");
    
    tempoAnterior = tempoAtual;
  }
  
  timeSpinning = NULL;
  leftWheelSpeed = NULL;
  rightWheelSpeed = NULL;
  
  Serial.println("Enter a code (options: f (forward), b (backward), h (help):");
  
  while (Serial.available() == 0) {}
  
  userInput = Serial.readStringUntil('\n');  // Read the input until a newline character

  // Convert the command letter to uppercase
  codeLetter = toupper(userInput.charAt(0));

  // Parse the numbers using strtok
  char* token = strtok((char*)userInput.c_str() + 2, ",");
  timeSpinning = atoi(token);
  token = strtok(NULL, ",");
  leftWheelSpeed = atoi(token);
  token = strtok(NULL, ",");
  rightWheelSpeed = atoi(token);

  if (codeLetter == 'F') {
    if (timeSpinning != NULL && leftWheelSpeed != NULL && rightWheelSpeed != NULL) {
      
    } else {
      Serial.println("Invalid code. Type h to help.");
    }
  }
  else if (codeLetter == 'B') {
    
  }
  else if (codeLetter == 'H') {
    Serial.println("HELP");
    Serial.println("F - forward");
    Serial.println("B - Backward");
    Serial.println("Template: F,1,2,3");
    Serial.println("1 - 1 second");
    Serial.println("2 - left wheel speed");
    Serial.println("3 - right wheel speed");
    Serial.println("Possible speed values: 1, 2, 3, 4, 5");
  } else {
    Serial.println("Invalid code. Type h to help.");
  }
  
}
