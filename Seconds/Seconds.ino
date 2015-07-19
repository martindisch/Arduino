#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int contrastPin = 9;
const int buttonPin = 6;
char str[4];
unsigned long seconds = 0;
unsigned long startMillis;
unsigned long currentMillis;

void setup() {
  lcd.begin(16, 2);
  pinMode(contrastPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  analogWrite(contrastPin, 50);
  lcd.print("Press the button");
  lcd.setCursor(0, 1);
  lcd.print("to start time");
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    count();
  }
  delay(100);
}

void count() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LC: ");
  lcd.setCursor(0, 1);
  lcd.print("MC: ");
  startMillis = millis();
  delay(1000);
  while (digitalRead(buttonPin) == LOW) {
    currentMillis = millis();
    seconds++;
    lcd.setCursor(4, 0);
    lcd.print(seconds);
    lcd.setCursor(4, 1);
    lcd.print((currentMillis - startMillis) / 1000);
    delay(1000);
  }
  seconds = 0;
  lcd.setCursor(0, 0);
  lcd.print("Press the button");
  lcd.setCursor(0, 1);
  lcd.print("to start time");
}

