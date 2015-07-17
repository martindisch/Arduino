const int sensorPin = A0;
const float baselineTemp = 24.0;

int sensorVal, lightAmount;
float voltage, temperature;

void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 5; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  lightAmount = 0;
  if (temperature >= baselineTemp + 2) {
    lightAmount = 1;
    if (temperature >= baselineTemp + 4) {
      lightAmount = 2;
      if (temperature >= baselineTemp + 6) {
        lightAmount = 3;
      }
    }
  }
  light(lightAmount);

  delay(500);
}

void light(int amount) {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  if (amount >= 1) {
    digitalWrite(2, HIGH);
    if (amount >= 2) {
      digitalWrite(3, HIGH);
      if (amount >= 3) {
        digitalWrite(4, HIGH);
      }
    }
  }
}

