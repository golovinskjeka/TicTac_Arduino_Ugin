#include "joystick.h"
#include <Arduino.h>

Joystick::Joystick(int vPin, int hPin, int bPin, int lPin) {
  vertPin = vPin;
  horzPin = hPin;
  buttonPin = bPin;
  ledPin = lPin;
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(ledPin, OUTPUT);
}

void Joystick::updateVal() {
  vertVal = analogRead(vertPin);
  horzVal = analogRead(horzPin);
  buttState = digitalRead(buttonPin);
}