#define ANALOG_INPUT A0
#define LED 2

int analogValue = 0;
int ledState = 0;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledState);
}

void loop() {
  analogValue = analogRead(ANALOG_INPUT);
  ledState = !ledState;
  digitalWrite(LED, ledState);
  delay(analogValue);
}