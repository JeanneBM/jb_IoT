#define pirPin 0
#define buzzPin 16

void setup()  
{
  Serial.begin(9600);
  pinMode(pirPin,INPUT);
  pinMode(buzzPin, OUTPUT); 
  digitalWrite(pirPin,LOW);
  
  Serial.println("Calibrating...");
  delay(20000);
}

void loop()  
{
    if(digitalRead(pirPin)==HIGH) {
      Serial.println("Movement detected!");
        tone(buzzPin, 500); 
        delay(1000);       
        noTone(buzzPin);     
        delay(1000);        
    }
    else {
      Serial.println("Nothing.");
    }
    delay(1000);
}