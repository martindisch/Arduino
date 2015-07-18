#include <Servo.h>

Servo myServo;
short mood = 0;
bool moodChanged = false;
short angle = 0;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  Serial.println("Type anything to start execution");
  while (Serial.available() == 0) {}
  Serial.read();
}

void loop() {
  if (digitalRead(2) == HIGH) {
    moodChanged = true;
    mood = 0;
    Serial.println("Pressed 2");
  }
  else if (digitalRead(3) == HIGH) {
    moodChanged = true;
    mood = 1;
    Serial.println("Pressed 3");
  }
  else if (digitalRead(4) == HIGH) {
    moodChanged = true;
    mood = 2;
    Serial.println("Pressed 4");
  }
  if (moodChanged) {
    angle = map(mood, 0, 2, 0, 167);
    Serial.print("Mood: ");
    Serial.print(mood);
    Serial.print(", Angle: ");
    Serial.println(angle);
    myServo.write(angle);
    moodChanged = false;
  }
  delay(250);
}
