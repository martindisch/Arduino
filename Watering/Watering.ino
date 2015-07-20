#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int contrastPin = 6;
const int contrast = 40;

const int gate = 7;
int mode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(gate, OUTPUT);
  Serial.println("Enter 0 or 1");

  lcd.begin(16, 2);
  pinMode(contrastPin, OUTPUT);
  analogWrite(contrastPin, contrast);
  lcd.print("Type 0 or 1");
  lcd.setCursor(0, 1);
  lcd.print("in serial");
}

void loop() {
  if (Serial.available()) {
    mode = Serial.parseInt();
    if (mode == 0) {
      digitalWrite(gate, LOW);
    }
    else {
      digitalWrite(gate, HIGH);
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("New value ");
    lcd.print(mode);
    lcd.setCursor(0, 1);
    lcd.write("Enter 0 or 1");
  }
}
