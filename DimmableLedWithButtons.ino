// Copyright 2021 Hugo Ruivo.

const int incButtonPin = A0;
const int decButtonPin = A1;
const int ledPin = 3;

int currentLedBrightness = 0;
int lastIncButtonState = 0;
int lastDecButtonState = 0;

int lastButtonPushState = 0;

int clampBrightness(int val, int min, int max) {
  if (val < min) return min;
  if (val > max) return max;

  return val;
}

void setup() {
  Serial.begin(9600);
  
  pinMode(incButtonPin, INPUT);
  pinMode(decButtonPin, INPUT);
  
  pinMode(ledPin, OUTPUT);

  delay(100);

  digitalWrite(ledPin, LOW);
}

void loop() {
  int pushState = 0;
  
  if (digitalRead(incButtonPin) > 0)
    pushState = 1;
  else if (digitalRead(decButtonPin) > 0)
    pushState = -1;

  if (pushState != lastButtonPushState && pushState != 0)
  {
    currentLedBrightness = clampBrightness(currentLedBrightness + pushState, 0, 255);

    analogWrite(ledPin, currentLedBrightness);

    Serial.print("Current Brightness: ");
    Serial.println(currentLedBrightness);
  }

  lastButtonPushState = pushState;

  delay(1);
}
