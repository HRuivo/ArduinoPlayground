// Copyright 2021 Hugo Ruivo.

const int readPin = A0;
int V2 = 0;

float convertToVoltage(int readValue) {
  return (5./1023.)*(float)readValue;
}

void setup() {
  pinMode(readPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  V2 = analogRead(readPin);

  Serial.print("Voltage 2: ");
  Serial.println(convertToVoltage(V2));

  delay(500);
}
