#include <CapacitiveSensor.h>

const int gatePin = 11;
const int tempPin = A0;
const int lightPin = A1;
const int greenLED = 8;
int command, tempVal, outputValue;
bool motorOn = false;
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

void setup() {
  Serial.begin(9600);
  pinMode(gatePin, OUTPUT);
  pinMode(tempPin, INPUT);
  pinMode(lightPin, INPUT);
  pinMode(greenLED, OUTPUT);
  //Serial.println("Enter 0 or 1");
}

void loop() {
  if (Serial.available()) {
    command = Serial.parseInt();
    switch (command) {
      case 0:
        Serial.println("Stopping motor");
        digitalWrite(gatePin, LOW);
        motorOn = false;
        digitalWrite(greenLED, LOW);
      break;
      case 1:
        Serial.println("Starting motor");
        startMotor();
      break;
      case 2:
        readTemp();
      break;
      case 3:
        readLight();
      break;
    }
  }
  delay(500);
}

void startMotor() {
  motorOn = true;
  outputValue = 0;
  while (outputValue < 256) {
    analogWrite(gatePin, outputValue);
    outputValue++;
    delay(10);
  }
  digitalWrite(greenLED, HIGH);
}

void readTemp() {
  tempVal = analogRead(tempPin);
  Serial.print("Temperature: ");
  Serial.println(map(tempVal, 0, 1023, -50, 450));
}

void readLight() {
  tempVal = analogRead(lightPin);
  Serial.print("Light: ");
  Serial.println(tempVal);
}

void readTouch() {
  tempVal = capSensor.capacitiveSensor(30);
  Serial.print("Cap value: ");
  Serial.println(tempVal);
}

