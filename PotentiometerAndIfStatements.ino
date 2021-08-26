const int readPin = A1;
const int redLedPin = 9;

float voltageWarningThreshold = 3.;

// converts pin read to voltage value
float pinReadToVoltage(int readValue, int maxVoltage = 5) {
  return ((float)maxVoltage/1023.)*(float)readValue;
}

void setup() {
  Serial.begin(9600);

  pinMode(readPin, INPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  float currentVoltageFromPotentiometer =
    pinReadToVoltage(analogRead(readPin));

  if (currentVoltageFromPotentiometer >= voltageWarningThreshold) {
    digitalWrite(redLedPin, HIGH);
  } else {
    digitalWrite(redLedPin, LOW);
  }

  Serial.print("Current Voltage: ");
  Serial.println(currentVoltageFromPotentiometer);
  
  delay(250);
}
