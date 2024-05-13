#define ANALOG_INPUT A0
#define LED 2

int analogValue = 0;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  analogValue = analogRead(ANALOG_INPUT);
  analogWrite(LED, analogValue);
  delay(20);
}