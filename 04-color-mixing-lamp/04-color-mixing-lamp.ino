const int PIN_IN_GREEN = 9;
const int PIN_IN_RED = 10;
const int PIN_IN_BLUE = 11;

const int PIN_SENSOR_RED = A0;
const int PIN_SENSOR_GREEN = A1;
const int PIN_SENSOR_BLUE = A2;

int valueRed = 0;
int valueGreen = 0;
int valueBlue = 0;

int valueSensorRed = 0;
int valueSensorGreen = 0;
int valueSensorBlue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_IN_GREEN, OUTPUT);
  pinMode(PIN_IN_RED, OUTPUT);
  pinMode(PIN_IN_BLUE, OUTPUT);
}

void loop() {
  valueSensorRed = analogRead(PIN_SENSOR_RED);
  delay(5);
  valueSensorGreen = analogRead(PIN_SENSOR_GREEN);
  delay(5);
  valueSensorBlue = analogRead(PIN_SENSOR_BLUE);

  Serial.print("Raw Sensor Values\tRed: ");
  Serial.print(valueSensorRed);
  Serial.print("\tGreen: ");
  Serial.print(valueSensorGreen);
  Serial.print("\tBlue: ");
  Serial.println(valueSensorBlue);

  valueRed = valueSensorRed / 4;
  valueGreen = valueSensorGreen / 4;
  valueBlue = valueSensorBlue / 4;

  Serial.print("Color Values\tRed: ");
  Serial.print(valueRed);
  Serial.print("\tGreen: ");
  Serial.print(valueGreen);
  Serial.print("\tBlue: ");
  Serial.println(valueBlue);

  analogWrite(PIN_IN_RED, valueRed);
  analogWrite(PIN_IN_GREEN, valueGreen);
  analogWrite(PIN_IN_BLUE, valueBlue);
}

// vim: sw=2:ts=2:sts=2
