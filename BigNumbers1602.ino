#include <LiquidCrystal.h>
#include <Wire.h>
#include <BigNumbers.h>
#include "DS3231.h" // 使用的DS3231 RTC模块

RTClib RTC;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
BigNumbers bigNum(&lcd);

int H;
int M;
int S;


void setup() {

  TCCR1B = TCCR1B & 0b11111000 | 0x01; //for Arduino Uno
  //TCCR2B = TCCR1B & 0b11111000 | 0x01; //for Arduino Mega

  Serial.begin(9600);
  lcd.begin(16, 2);
  bigNum.begin();
  Wire.begin();
  lcd.clear();
}

void loop() {

  DateTime now = RTC.now();
  H = now.hour();
  M = now.minute();
  S = now.second();

  //大字体
  bigNum.displayLargeInt(H, 0, 2, true);
  bigNum.displayLargeInt(M, 7, 2, true);

  
  lcd.setCursor(6,0);
  lcd.print("*");
  lcd.setCursor(6,1);
  lcd.print("*");
  lcd.setCursor(13,1);
  lcd.print(":");

  if(S >= 10){
    lcd.setCursor(14,1);
    lcd.print(S);
  }else{
    lcd.setCursor(15,1);
    lcd.print(S);
    lcd.setCursor(14,1);
    lcd.print("0");
    
  }
}
