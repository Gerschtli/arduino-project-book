#include <Servo.h>

const int PIN_POTENTIOMETER = A0;
const int PIN_SERVO = 9;

Servo servo;
int valuePotentiometer;
int angle;

void setup() {
  servo.attach(PIN_SERVO);

  Serial.begin(9600);
}

void loop() {
  valuePotentiometer = analogRead(PIN_POTENTIOMETER);

  Serial.print("value of pot: ");
  Serial.print(valuePotentiometer);

  angle = map(valuePotentiometer, 0, 1023, 0, 179);

  Serial.print(", angle: ");
  Serial.println(angle);

  servo.write(angle);

  delay(15);
}

// vim: sw=2:ts=2:sts=2
