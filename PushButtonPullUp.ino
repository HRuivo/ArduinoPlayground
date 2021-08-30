// Copyright 2021 Hugo Ruivo.

const int LedPin = 8;
const int ReadPin = 12;
int lastPushState = 0;
int currentLedState = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(LedPin, OUTPUT);
  pinMode(ReadPin, INPUT);
}

void loop() {
  int pushState = digitalRead(ReadPin);

  if (pushState != lastPushState && pushState == 0)
  {
    Serial.println("Changed");
    currentLedState = !currentLedState;

    digitalWrite(LedPin, currentLedState);
  }

  lastPushState = pushState;

  delay(10);
}
