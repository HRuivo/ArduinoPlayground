const int pin = 3;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  analogWrite(pin, 255);
  delay(100);
  analogWrite(pin, 0);
  delay(500);

  int i = 0;
  while (i++ < 255) {
    analogWrite(pin, i);
    delay(25);
  }

  delay(1000);
}
