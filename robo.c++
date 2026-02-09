#include <Servo.h>

/* ===== PIN DEFINITIONS ===== */
// Motor Driver
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int ENA = 5;
int ENB = 6;

// Ultrasonic Sensor
int trigPin = 2;
int echoPin = 3;

// Sensors
int pirPin   = 12;   // Human detection
int flamePin = A0;   // Fire sensor
int gasPin   = A1;   // Gas sensor

// Output
int buzzer = 13;

// Servo
int servoPin = 4;
Servo scanServo;

// Bluetooth
char command;
bool autoMode = false;

/* ===== SETUP ===== */
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(pirPin, INPUT);
  pinMode(flamePin, INPUT);
  pinMode(gasPin, INPUT);

  pinMode(buzzer, OUTPUT);

  scanServo.attach(servoPin);
  scanServo.write(90);

  Serial.begin(9600);
}

/* ===== LOOP ===== */
void loop() {

  if (Serial.available()) {
    command = Serial.read();

    if (command == 'A') autoMode = true;
    if (command == 'M') autoMode = false;

    if (!autoMode) manualControl();
  }

  if (autoMode) autonomousMode();

  safetyCheck();
}

/* ===== MANUAL CONTROL ===== */
void manualControl() {
  if (command == 'F') forward();
  else if (command == 'B') backward();
  else if (command == 'L') left();
  else if (command == 'R') right();
  else if (command == 'S') stopCar();
}

/* ===== AUTONOMOUS MODE ===== */
void autonomousMode() {
  long distance = getDistance();

  if (distance < 25) {
    stopCar();
    delay(300);

    scanServo.write(30);
    delay(400);
    long leftDist = getDistance();

    scanServo.write(150);
    delay(400);
    long rightDist = getDistance();

    scanServo.write(90);

    if (leftDist > rightDist)
      left();
    else
      right();

    delay(500);
  } else {
    forward();
  }
}

/* ===== SAFETY CHECK ===== */
void safetyCheck() {

  if (digitalRead(pirPin) == HIGH) {
    stopCar();
    digitalWrite(buzzer, HIGH);
    delay(500);
  }

  if (analogRead(flamePin) < 300) {
    stopCar();
    digitalWrite(buzzer, HIGH);
    delay(500);
  }

  if (analogRead(gasPin) > 400) {
    stopCar();
    digitalWrite(buzzer, HIGH);
    delay(500);
  }

  digitalWrite(buzzer, LOW);
}

/* ===== ULTRASONIC FUNCTION ===== */
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  return duration * 0.034 / 2;
}

/* ===== MOTOR FUNCTIONS ===== */
void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
