#include <CapacitiveSensor.h>

const int gatePin = 11;
const int tempPin = A0;
const int lightPin = A1;
const int greenLED = 8;
int mode, tempVal, outputValue;
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
    mode = Serial.parseInt();
    if (mode == 0) {
      Serial.println("Stopping motor");
      //digitalWrite(gatePin, LOW);
      digitalWrite(greenLED, LOW);
    }
    else {
      Serial.println("Starting motor");
      startMotor();
    }
    delay(500);
  }
  readTemp();
  delay(10);
  readLight();
  delay(10);
  //readTouch();
  delay(600000);
}

void startMotor() {
  /*outputValue = 0;
  while (outputValue < 256) {
    analogWrite(gatePin, outputValue);
    outputValue++;
    delay(10);
  }*/
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

