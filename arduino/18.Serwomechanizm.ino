#include <Servo.h> 
#define servoPin 5

Servo myservo;
    
int odebraneDane; 

void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);
}
  
void loop() {
  if(Serial.available() > 0) {
    odebraneDane = Serial.parseInt(); 
    Serial.println(odebraneDane); 
        if(odebraneDane > -1 && odebraneDane < 181){
            myservo.write(odebraneDane);
        }
        else{ 
          Serial.println("You can only write 0-180 range.");
        }
    delay(50);
  }
}