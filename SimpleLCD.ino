// Copyright 2021 Hugo Ruivo.

#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Watch me count");

  delay(1000);

  for (int i = 0; i <= 10; i++){
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(500);
  }
  lcd.clear();
}
