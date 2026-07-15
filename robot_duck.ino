#include <Servo.h>

Servo neck;

// Pin definitions
const int BUTTON = 2;

const int LEFT_EYE = 4;
const int RIGHT_EYE = 5;

const int TRIG = 6;
const int ECHO = 7;

const int SERVO = 9;
const int PIR = 10;

// Future Sensors
// const int LIGHT = A1;
// const int DHTPIN = 3;
// const int MIC = A0;

// Function Prototypes 
bool isButtonPressed();
bool detectMotion();
float readDistance();

void updateEyes(bool buttonPressed);
void updateServo(bool buttonPressed);

void setup() {

  pinMode(BUTTON, INPUT_PULLUP);

  pinMode(LEFT_EYE, OUTPUT);
  pinMode(RIGHT_EYE, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(PIR, INPUT);

  neck.attach(SERVO);
  neck.write(0);     // Duck starts facing forward

  Serial.begin(9600);
}

void loop() {

  // Read inputs
  bool buttonPressed = isButtonPressed();
  bool motion = detectMotion();
  float distance = readDistance();

  // Update outputs
  updateEyes(buttonPressed);
  updateServo(buttonPressed);

  // report PID and/or UltraSonic sensor data
  if (motion) {
    Serial.println("Motion detected!");
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);
}

// Functions (much needed)

// Returns true when the button is pressed
bool isButtonPressed() {
  return digitalRead(BUTTON) == LOW;
}

// Returns true when motion is detected
bool detectMotion() {
  return digitalRead(PIR);
}

// Measures distance using the HC-SR04
float readDistance() {

  // Clear the trigger pin
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Measure the echo time
  long duration = pulseIn(ECHO, HIGH);

  // Convert to centimeters
  float distance = duration * 0.0343 / 2.0;

  return distance;
}

// Controls the duck's eyes
void updateEyes(bool buttonPressed) {

  if (buttonPressed) {
    digitalWrite(LEFT_EYE, HIGH);
    digitalWrite(RIGHT_EYE, HIGH);
  } else {
    digitalWrite(LEFT_EYE, LOW);
    digitalWrite(RIGHT_EYE, LOW);
  }

}

// Controls the duck's neck
void updateServo(bool buttonPressed) {

  if (buttonPressed) {
    neck.write(90);
  } else {
    neck.write(0);
  }

}