const int optoPin = 2;
int mode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(optoPin, OUTPUT);
  Serial.println("Enter 0 or 1");
}

void loop() {
  if (Serial.available()) {
    mode = Serial.parseInt();
    if (mode == 0) {
      digitalWrite(optoPin, LOW);
    }
    else {
      digitalWrite(optoPin, HIGH);
    }
    Serial.print("New value ");
    Serial.println(mode);
    Serial.println("Enter 0 or 1");
  }
}
