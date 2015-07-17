const int sensorPin = A0;
const float baselineTemp = 23.0;
const float interval = 5 * 60000;
const int waitDuration = 250;

int sensorVal, lightAmount;
float voltage, temperature;
float temperatures[300];
long loopCounter = 0;
int storeIndex = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(8, INPUT);
}

void loop() {
  sensorVal = analogRead(sensorPin);
  voltage = (sensorVal/1024.0) * 5.0;
  temperature = (voltage - .5) * 100;

  lightAmount = 0;
  for (int i = 1; i < 7; i++) {
    if (temperature >= baselineTemp + i) {
      lightAmount = i;
    }
    else {
      break;
    }
  }
  light(lightAmount);

  if (loopCounter % (int) (interval / waitDuration) == 0) {
    store(temperature);
  }

  input();

  loopCounter++;
  delay(waitDuration);
}

void light(int amount) {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  if (amount >= 1) {
    digitalWrite(2, HIGH);
    if (amount >= 2) {
      digitalWrite(3, HIGH);
      if (amount >= 3) {
        digitalWrite(4, HIGH);
        if (amount >= 4) {
          digitalWrite(5, HIGH);
          if (amount >= 5) {
            digitalWrite(6, HIGH);
            if (amount >= 6) {
              digitalWrite(7, HIGH);
            }
          }
        }
      }
    }
  }
}

void input() {
  if (digitalRead(8) == HIGH) {
    for (int i = 0; i < storeIndex; i++) {
      Serial.println(temperatures[i]);
    }
    storeIndex = 0;
  }
}

void store(float temperature) {
  temperatures[storeIndex] = temperature;
  storeIndex++;
}

