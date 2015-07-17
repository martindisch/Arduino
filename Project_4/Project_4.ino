const int greenLED = 9;
const int redLED = 11;
const int blueLED = 10;

const int redSensor = A0;
const int greenSensor = A1;
const int blueSensor = A2;

int redOut = 0;
int greenOut = 0;
int blueOut = 0;

int redIn = 0;
int greenIn = 0;
int blueIn = 0;

void setup() {
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  redIn = analogRead(redSensor);
  delay(5);
  greenIn = analogRead(greenSensor);
  delay(5);
  blueIn = analogRead(blueSensor);

  Serial.print("Raw sensor values \t Red: ");
  Serial.print(redIn);
  Serial.print("\t Green: ");
  Serial.print(greenIn);
  Serial.print("\t Blue: ");
  Serial.println(blueIn);

  redOut = redIn / 4;
  greenOut = greenIn / 4;
  blueOut = blueIn / 4;

  analogWrite(redLED, redOut);
  analogWrite(greenLED, greenOut);
  analogWrite(blueLED, blueOut);
}
