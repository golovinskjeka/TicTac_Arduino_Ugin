#pragma once

#include <U8g2lib.h>

#include "game.h"

class Display{
  private:
    U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2;
    void cross(int x, int y);
    void circle(int x, int y);

  public: 
    Display();
    void init();
    void refresh(Game &game);
    void crossCursor(int x, int y); 
    void circleCursor(int x, int y);
};