int incomingByte = 0;
const int ledPin = 2;
int counter = 0;
char command;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.print("You sent me        ");
    Serial.println(command);
    if (command == 'a') {
      digitalWrite(ledPin, HIGH);
    }
    else if (command == 't') {
      digitalWrite(ledPin, LOW);
    }
  }
  // Take it slow so we don't skip anything
  delay(100);
}
