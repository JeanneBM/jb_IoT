#define PHOTORESISTOR A0
#define LED 2

int analogValue = 0;
int brightness;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(PHOTORESISTOR);
  Serial.print("Analog read: ");
  Serial.println(analogValue);
  brightness = map(analogValue, 40, 250, 200, 0); // map(value, fromLow, fromHigh, toLow, toHigh)
  Serial.print("Brightness: ");
  Serial.println(brightness);
  analogWrite(LED, brightness);
  delay(10);
}