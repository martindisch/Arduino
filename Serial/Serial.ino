int incomingByte = 0;
const int ledPin = 2;
int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  Serial.print("I'm at count ");
  Serial.println(counter);
  counter++;
  delay(100);
}
