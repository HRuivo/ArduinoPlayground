// Copyright 2021 Hugo Ruivo.

const int buzzPin = 8;
const int potPin = A3;

int highPitchDelay = 60;
int lowPitchDelay = 1000;

void setup() {
  Serial.begin(9600);
  
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int potVal = analogRead(potPin);

  int buzzDelay = (int)(lerp(1000., 60., (float)potVal / 1023.));
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(buzzDelay);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(buzzDelay);
}

int lerp(float a, float b, float f) {
  return a + f * (b - a);
}
