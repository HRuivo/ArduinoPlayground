const int readPin = A1;
const int redLedPin = 9;
const int greenLedPin = 10; 

float voltageWarningThreshold = 4.;
float optimalMinVoltage = 2.f;

// converts pin read to voltage value
float pinReadToVoltage(int readValue, int maxVoltage = 5) {
  return ((float)maxVoltage/1023.)*(float)readValue;
}

void setup() {
  Serial.begin(9600);

  pinMode(readPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  float currentVoltageFromPotentiometer =
    pinReadToVoltage(analogRead(readPin));

  if (currentVoltageFromPotentiometer >= optimalMinVoltage &&
      currentVoltageFromPotentiometer < voltageWarningThreshold) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
  } else if (currentVoltageFromPotentiometer >= voltageWarningThreshold) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }

  Serial.print("Current Voltage: ");
  Serial.println(currentVoltageFromPotentiometer);
  
  delay(250);
}