#pragma once

class Joystick {
  public:
    int vertPin;
    int horzPin;
    int buttonPin;
    int ledPin;

    int vertVal;
    int horzVal;
    bool buttState;

    Joystick(int vPin, int hPin, int bPin, int lPin);
    void updateVal();

};