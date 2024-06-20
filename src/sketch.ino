#include <Arduino.h>
#include <SPI.h>
#include "joystick.h"
#include "display.h"
#include "game.h"

Joystick player[] = {
  {/*vertPin*/14, /*horzPin*/27, /*buttonPin*/26, /*ledPin*/18},
  {/*vertPin*/25, /*horzPin*/33, /*buttonPin*/32, /*ledPin*/19}
};

Display display;
Game game;

void setup() {
  display.init();
}

void loop() {

  display.refresh(game);

  for (int i = 0; i < 2; i++) {
    player[i].updateVal();
  }

  game.checkAction(player);

  game.winner =  game.checkWin();

  if(game.restartFlag){
    game.restart();
  }
 
  // printf("\n");
  delay(100);
}




