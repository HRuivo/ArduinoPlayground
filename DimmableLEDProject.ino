const int potPin = A3;
const int ledPin = 9;

float calculateLedValue(int potVal) {
  return (255./1023.) * potVal;
}

void setup() {
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potVal = analogRead(potPin);
  float ledVal = calculateLedValue(potVal);
  
  analogWrite(ledPin, ledVal);

  delay(100);
}
