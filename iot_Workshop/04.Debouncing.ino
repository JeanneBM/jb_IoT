#define LED 2
#define BUTTON 14

String msg = "";
int lastButtonState = LOW;
int buttonState = HIGH;
int clickCounter = 0;
unsigned long lastDebounceTime = 0;   
int debounceDelay = 50; /* variable describing how long 
                        the "pressure" on the button should last,
                        to consider it as the wanted press */
int ledState = 0;
String ledStateMsg;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledState);
  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Witaj na Workshop IoT 2022!");
}

void loop() {
  int currentButtonState = digitalRead(BUTTON);

  if(currentButtonState != lastButtonState) { // if the "pressure" was detected
    lastDebounceTime = millis();
  }

  if(millis()-lastDebounceTime > debounceDelay) { // can we consider it as the wanted press
    if(currentButtonState != buttonState) { // if the button state has changed
      buttonState = currentButtonState;

      if(buttonState == HIGH) {
        ledState = LOW;
        ledStateMsg = "LED is OFF";
      } else {
        ledState = HIGH;
        ledStateMsg = "LED is ON";
        clickCounter++;
        Serial.println(clickCounter);
      }
      
      digitalWrite(LED, ledState);
      Serial.println(ledStateMsg);
    }
  }
  lastButtonState = currentButtonState;
}
