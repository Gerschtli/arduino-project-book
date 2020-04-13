const int PIN_PIEZO = 8;
const int PIN_SENSOR = A0;
const int PIN_LED = LED_BUILTIN; // 13

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
int pitch;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(PIN_SENSOR);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  digitalWrite(PIN_LED, LOW);
}

void loop() {
  sensorValue = analogRead(PIN_SENSOR);
  pitch = map(sensorValue, sensorLow, sensorHigh, 400, 900);
  tone(PIN_PIEZO, pitch, 20); // play 20 ms
  delay(10);
}

// vim: sw=2:ts=2:sts=2
