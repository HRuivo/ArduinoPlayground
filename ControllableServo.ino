// Copyright 2021 Hugo Ruivo.

#include <Servo.h>

const int servoPin = 9;
const int potPin = A0;

int servoPos = 0;
Servo myServo;

int lerp(float a, float b, float f) {
  return a + f * (b - a);
}

void setup() {
  Serial.begin(9600);

  pinMode(potPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  int potVal = analogRead(potPin);
  servoPos = lerp(0., 180., (float)potVal / 1023.);
  myServo.write((int)servoPos);

  Serial.println(servoPos);

  delay(100);
}
