const int PIN_SENSOR = A0;
float baselineTemp;

void setup() {
  Serial.begin(9600); // 9600 bits per second

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  int sensorVal = getSensorVal();
  float voltage = getVoltage(sensorVal);
  baselineTemp = getTemperature(voltage);

  Serial.print("Baseline Temperature: ");
  Serial.print(baselineTemp);
  Serial.println(" °C");
}

void loop() {
  int sensorVal = getSensorVal();
  float voltage = getVoltage(sensorVal);
  float temperature = getTemperature(voltage);

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print(" V, Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1);
}


int getSensorVal() {
  return analogRead(PIN_SENSOR); // between 0 and 1023
}

float getVoltage(int sensorVal) {
  return sensorVal / 1024.0 * 5;
}

float getTemperature(float voltage) {
  return (voltage - .5) * 100;
}
