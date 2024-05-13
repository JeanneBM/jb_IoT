#define LED 2              
#define BUTTON 14

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(BUTTON) == LOW) { // if the button is pushed
    digitalWrite(LED, HIGH);   
  } else {
    digitalWrite(LED, LOW); 
  }
}
