#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int contrastPin = 9;
char str[4];

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(contrastPin, OUTPUT);
  analogWrite(contrastPin, 50);
  lcd.print("Type the current");
  lcd.setCursor(0, 1);
  lcd.print("time in Serial");
  Serial.println("Write the time (hh:mm) to start");
}

void loop() {
  if (Serial.available() == 4) {
    for (byte i=0; i<4; i++){
      str[i] = Serial.read();
    }
    Serial.println(str);
  }
  delay(100);
}
