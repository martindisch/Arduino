const int switchPin = 8;
unsigned long previousTime = 0;
short switchState = 0;
short prevSwitchState = 0;
short led = 2;
long interval = 10000;

void setup() {
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
    if (led == 7) {
      for (int i = 2; i < 8; i++) {
      digitalWrite(i, LOW);
    }
    led = 2;
    previousTime = currentTime;
    }
  }
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    for (int i = 2; i < 8; i++) {
      digitalWrite(i, LOW);
    }
    led = 2;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
}
