#include "led_functions.h"
#include "input_functions.h"

#define analogPin A0
#define rPin 16
#define gPin 5
#define bPin 4
#define photoresistorVin 14
#define potentiometerVin 12

int brightnessVal;
int colorVal;

void setup() {
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(photoresistorVin, OUTPUT);
  pinMode(potentiometerVin, OUTPUT);
}

void loop() {
  brightnessVal = map(readAnalogMultiInput(analogPin, photoresistorVin), 60, 215, 0, 255);
  colorVal = map(readAnalogMultiInput(analogPin, potentiometerVin), 0, 1024, 0, 255);

  setRGB(rPin, gPin, bPin, calculateRGBColor(colorVal), brightnessVal);
}
