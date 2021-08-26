const int voltPin = A1;
float V2 = 0;

void setup() {
  Serial.begin(9600);

  pinMode(voltPin, INPUT);
}

void loop() {
  int readVal = analogRead(voltPin);
  V2 = (5./1023.)*readVal;

  Serial.print("Output Voltage = ");
  Serial.println(V2);

  delay(250);
}
