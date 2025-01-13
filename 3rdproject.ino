// Define motor driver pins
#define ENA 9  // Speed control for left motor
#define ENB 10 // Speed control for right motor
#define IN1 2  // Left motor forward
#define IN2 3  // Left motor backward
#define IN3 4  // Right motor forward
#define IN4 5  // Right motor backward

// Define light pins
#define LEFT_LIGHT 6   // Left indicator light
#define RIGHT_LIGHT 7  // Right indicator light

void setup() {
  // Set motor driver pins as output
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set light pins as output
  pinMode(LEFT_LIGHT, OUTPUT);
  pinMode(RIGHT_LIGHT, OUTPUT);

  // Start serial communication for Bluetooth
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the Bluetooth command

    switch (command) {
      case 'F': // Forward
        moveForward();
        break;
      case 'B': // Backward
        moveBackward();
        break;
      case 'L': // Left
        turnLeft();
        blinkLeftLight();
        break;
      case 'R': // Right
        turnRight();
        blinkRightLight();
        break;
      case 'S': // Stop
        stopMotors();
        break;
    }
  }
}

// Function definitions
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200); // Adjust speed (0-255)
  analogWrite(ENB, 200);
  turnOffLights(); // Turn off indicator lights
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  turnOffLights(); // Turn off indicator lights
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  turnOffLights(); // Turn off indicator lights
}

void blinkLeftLight() {
  digitalWrite(RIGHT_LIGHT, LOW); // Ensure the right light is off
  for (int i = 0; i < 3; i++) {   // Blink 3 times
    digitalWrite(LEFT_LIGHT, HIGH);
    delay(300);
    digitalWrite(LEFT_LIGHT, LOW);
    delay(300);
  }
}

void blinkRightLight() {
  digitalWrite(LEFT_LIGHT, LOW); // Ensure the left light is off
  for (int i = 0; i < 3; i++) {  // Blink 3 times
    digitalWrite(RIGHT_LIGHT, HIGH);
    delay(300);
    digitalWrite(RIGHT_LIGHT, LOW);
    delay(300);
  }
}

void turnOffLights() {
  digitalWrite(LEFT_LIGHT, LOW);
  digitalWrite(RIGHT_LIGHT, LOW);
}
