// Copyright 2021 Hugo Ruivo.

#include <math.h>

const int pin01 = 2;
const int pin02 = 3;
const int pin03 = 4;
const int pin04 = 5;

double getFracPart(double decimal) {
  double y, d;
  y = modf(decimal, &d);

  return y;
}

void digitalPrintDecimal(const int decimal) {
  int num = (double)decimal;

    digitalWrite(pin01, getFracPart(num / 2.0)  >= 0.5 ? HIGH : LOW);
    digitalWrite(pin02, getFracPart(num / 4.0)  >= 0.5 ? HIGH : LOW);
    digitalWrite(pin03, getFracPart(num / 8.0)  >= 0.5 ? HIGH : LOW);
    digitalWrite(pin04, getFracPart(num / 16.0) >= 0.5 ? HIGH : LOW);
}

void setup() {
  pinMode(pin01, OUTPUT);
  pinMode(pin02, OUTPUT);
  pinMode(pin03, OUTPUT);
  pinMode(pin04, OUTPUT);

  digitalWrite(pin01, LOW);
  digitalWrite(pin02, LOW);
  digitalWrite(pin03, LOW);
  digitalWrite(pin04, LOW);

  Serial.begin(9600);
  
  delay(100);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    digitalPrintDecimal(i);
    delay(1000);
  }
}
