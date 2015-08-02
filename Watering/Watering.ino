#include <CapacitiveSensor.h>

const int gatePin = 11;
const int tempPin = A0;
const int lightPin = A1;
const int greenLED = 8;
int command, tempVal, outputValue;
float fTempVal;
bool motorOn = false;
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

void setup() {
  Serial.begin(9600);
  pinMode(gatePin, OUTPUT);
  pinMode(tempPin, INPUT);
  pinMode(lightPin, INPUT);
  pinMode(greenLED, OUTPUT);
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
      case 4:
        readCap();
      break;
      case 5:
        readTempOld();
      break;
    }
  }
  delay(500);
}

void startMotor() {
  digitalWrite(greenLED, HIGH);
  motorOn = true;
  /*outputValue = 0;
  while (outputValue < 256) {
    analogWrite(gatePin, outputValue);
    outputValue++;
    delay(10);
  }*/
  digitalWrite(gatePin, HIGH);
}

void readTemp() {
  tempVal = analogRead(tempPin);
  Serial.print("Temperature: ");
  Serial.println(map(tempVal, 0, 1023, -50, 450));
}

void readTempOld() {
  fTempVal = analogRead(tempPin);
  fTempVal = (fTempVal / 1024.0) * 5.0;
  fTempVal = (fTempVal - .5) * 100;
  Serial.print("Old temperature: ");
  Serial.println(fTempVal);
}

void readLight() {
  tempVal = analogRead(lightPin);
  Serial.print("Light: ");
  Serial.println(tempVal);
}

void readCap() {
  tempVal = capSensor.capacitiveSensorRaw(30);
  Serial.print("Cap value: ");
  Serial.println(tempVal);
}

