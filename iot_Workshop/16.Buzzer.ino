#define buzzer 16

void setup(){ 
  pinMode(buzzer, OUTPUT); 
}

void loop(){
  tone(buzzer, 500); // Send 500Hz sound signal...
  delay(1000);       
  noTone(buzzer);     
  delay(1000);        
}