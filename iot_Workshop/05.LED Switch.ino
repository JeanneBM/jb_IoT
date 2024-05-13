#define LED 2
#define BUTTON 14

int lastButtonState = LOW;
int buttonState = HIGH;
unsigned long lastDebounceTime = 0;
int debounceDelay = 50;
int ledState = 0;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledState);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  int currentButtonState = digitalRead(BUTTON);

  if(currentButtonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if(millis()-lastDebounceTime > debounceDelay) {
    if(currentButtonState != buttonState) {
      buttonState = currentButtonState;

      if(buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(LED, ledState);
  lastButtonState = currentButtonState;
}
