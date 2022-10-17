#define redPin 16
#define greenPin 5
#define bluePin 4
#define analogPin A0

int currentColorValueRed;
int currentColorValueGreen;
int currentColorValueBlue;
 
void setup()
{
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
}
 
void loop()
{
	int analogValue = map(analogRead(analogPin), 0, 1024, 255, 0);
	if (analogValue <= 42.5) {  // 1/6th of 255 is 42.5
		currentColorValueRed = 0;
		currentColorValueGreen = 255 - (analogValue * 6);
    currentColorValueBlue = 255;
   }
   
   if ((analogValue > 42.5) && (analogValue <= 85)) {
		currentColorValueRed = 0 + (analogValue - 43) * 6;
    currentColorValueGreen = 0;
		currentColorValueBlue = 255;
   }
   
   if ((analogValue > 85) && (analogValue <= 127.5)) {
    currentColorValueRed = 255;
    currentColorValueGreen = 0;
		currentColorValueBlue = 255 - (analogValue - 85) * 6;
   }
   
	if ((analogValue > 127.5) && (analogValue <= 170)) {
		currentColorValueRed = 255;
		currentColorValueGreen = 0 + (analogValue - 127.5) * 6;
    currentColorValueBlue = 0;
	}
   
	if ((analogValue > 170) && (analogValue <= 212.5)) {
		currentColorValueRed = 255 - (analogValue - 170) * 6;
		currentColorValueGreen = 255;
    currentColorValueBlue = 0;
	}
	
	if ((analogValue > 212.5) && (analogValue <= 255)) {
    currentColorValueRed = 0;
		currentColorValueGreen = 255;
		currentColorValueBlue = 0 + (analogValue - 212.5) * 6;
	}
   
	analogWrite(redPin, currentColorValueRed);
  analogWrite(greenPin, currentColorValueGreen);
	analogWrite(bluePin, currentColorValueBlue);
}