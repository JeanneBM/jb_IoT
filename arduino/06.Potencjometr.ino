#define ANALOG_INPUT A0

int analogValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(ANALOG_INPUT); // read the analog value
  Serial.println(analogValue);
  delay(250);
}