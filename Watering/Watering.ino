const int gate = 11;
int mode = 0;
int outputValue;

void setup() {
  Serial.begin(9600);
  pinMode(gate, OUTPUT);
  Serial.println("Enter 0 or 1");
}

void loop() {
  if (Serial.available()) {
    mode = Serial.parseInt();
    if (mode == 0) {
      Serial.println("Stopping motor");
      digitalWrite(gate, LOW);
    }
    else {
      Serial.println("Starting motor");
      startMotor();
    }
    delay(500);
  }
  delay(50);
}

void startMotor() {
  outputValue = 0;
  while (outputValue < 256) {
    analogWrite(gate, outputValue);
    outputValue++;
    delay(10);
  }
}

