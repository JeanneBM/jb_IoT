#define LED 2
#define BUTTON 14

String msg = "";
int lastButtonState = LOW;
int buttonState = LOW;
int clickCounter = 0;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Witaj na Workshop IoT 2022!");
}

void loop() {
  buttonState = digitalRead(BUTTON);

  if(buttonState != lastButtonState) {
    
    if(buttonState == LOW) { 
      digitalWrite(LED, HIGH);  
      msg = "LED is ON";
      clickCounter++;
      Serial.println(clickCounter);
    }

    if(buttonState == HIGH) { 
      digitalWrite(LED, LOW); 
      msg = "LED is OFF";
    }
  
    Serial.println(msg);

    lastButtonState = buttonState;
  }
}
