#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
const int contrastPin = 9;
int switchState = 0;
int prevSwitchState = 0;
int reply = 0;
int prevReply = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  pinMode(contrastPin, OUTPUT);
  analogWrite(contrastPin, 50);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal ball!");
  Serial.println("Type value from 0 to 255 for LCD contrast");
}

void loop() {
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      while (reply == prevReply) {
        reply = random(8);
      }
      prevReply = reply;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says:");
      lcd.setCursor(0, 1);
      switch (reply) {
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("No");
        break;
      }
    }
  }
  prevSwitchState = switchState;
  if (Serial.available()) {
    int contrast = Serial.parseInt();
    analogWrite(contrastPin, contrast);
    Serial.print("New contrast ");
    Serial.println(contrast);
    Serial.println("Type value from 0 to 255 for LCD contrast");
  }
  delay(100);
}
