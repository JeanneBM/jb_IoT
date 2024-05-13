#define analogPin A0
#define redPin 4
#define greenPin 5
#define bluePin 16
#define photoresistorVin 14
#define potentiometerVin 32

int analogValue;
int brightness;
int color;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(photoresistorVin, OUTPUT);
  pinMode(potentiometerVin, OUTPUT);
}

void loop() {
  
  digitalWrite(photoresistorVin, HIGH);
  analogValue = analogRead(analogPin);
  brightness = map(analogValue, 60, 215, 0, 255);
  digitalWrite(photoresistorVin, LOW);
  delay(10);

  digitalWrite(potentiometerVin, HIGH);
  analogValue = analogRead(analogPin);
  color = map(analogValue, 0, 1024, 0, 255);
  digitalWrite(potentiometerVin, LOW);
  delay(10);
  
  colorRGB(color, brightness);
}

void colorRGB(int color, int brightness) {
  int currentColorValueRed;
  int currentColorValueGreen;
  int currentColorValueBlue;

  	if (color <= 42.5) {
		currentColorValueRed = 255 - brightness;
		currentColorValueGreen = color * 6 - brightness;
		currentColorValueBlue = 0;
   }
   
   if ((color > 42.5) && (color <= 85)) {
		currentColorValueRed = 255 - (color - 43) * 6 - brightness;
		currentColorValueGreen = 255 - brightness;
		currentColorValueBlue = 0;
   }
   
   if ((color > 85) && (color <= 127.5)) {
		currentColorValueRed = 0;
		currentColorValueGreen = 255 - brightness;
		currentColorValueBlue = (color - 85) * 6 - brightness;
   }
   
	if ((color > 127.5) && (color <= 170)) {
		currentColorValueRed = 0;
		currentColorValueGreen = 255 - (color - 127.5) * 6 - brightness;
		currentColorValueBlue = 255 - brightness;
	}
   
	if ((color > 170) && (color <= 212.5)) {
		currentColorValueRed = (color - 170) * 6 - brightness;
		currentColorValueGreen = 0;
		currentColorValueBlue = 255 - brightness;
	}
	
	if ((color > 212.5) && (color <= 255)) {
		currentColorValueRed = 255 - brightness;
		currentColorValueGreen = 0;
		currentColorValueBlue = 255 - (color - 212.5) * 6 - brightness;
	}
   
	analogWrite(redPin, currentColorValueRed);
	analogWrite(bluePin, currentColorValueBlue);
	analogWrite(greenPin, currentColorValueGreen);
}