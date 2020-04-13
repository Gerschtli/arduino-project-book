int switchState = 0;
int redOn = 0;

int PIN_SWITCH = 2;
int PIN_LED_GREEN = 3;
int PIN_LED_RED_1 = 4;
int PIN_LED_RED_2 = 5;

void setup() {
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_RED_1, OUTPUT);
  pinMode(PIN_LED_RED_2, OUTPUT);
  pinMode(PIN_SWITCH, INPUT);
}

void loop() {
  switchState = digitalRead(PIN_SWITCH);

  if (switchState == LOW) { // button not pressed
    digitalWrite(PIN_LED_GREEN, HIGH);
    digitalWrite(PIN_LED_RED_1, LOW);
    digitalWrite(PIN_LED_RED_2, LOW);
  } else { // button is pressed
    digitalWrite(PIN_LED_GREEN, LOW);

    redOn ^= 1;

    if (redOn == 1) {
      digitalWrite(PIN_LED_RED_1, HIGH);
      digitalWrite(PIN_LED_RED_2, LOW);
    } else {
      digitalWrite(PIN_LED_RED_1, LOW);
      digitalWrite(PIN_LED_RED_2, HIGH);
    }

    delay(250); // 250 ms
  }
}
