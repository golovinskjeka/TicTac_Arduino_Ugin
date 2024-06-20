#include "game.h"


Game::Game() {
  playerTurn = 1;
  cursorX = 1;
  cursorY = 1;
  winner = -1;
  restartFlag = 0;

  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      board[j][i] = -1;
    }
  }
}

void Game::checkAction(Joystick* player) {
  if (player[playerTurn].vertVal >= 4095) {
    cursorY--;
    if (cursorY < 0) {
      cursorY = 0;
    }
    delay(200);
  }
  if (player[playerTurn].vertVal <= 0) {
    cursorY++;
    if (cursorY > 2) {
      cursorY = 2;
    }
    delay(200);
  }

  if (player[playerTurn].horzVal >= 4095) {
    cursorX--;
    if (cursorX < 0) {
      cursorX = 0;
    }
    delay(200);
  }
  if (player[playerTurn].horzVal <= 0) {
    cursorX++;
    if (cursorX > 2) {
      cursorX = 2;
    }
    delay(200);
  }

  if (player[playerTurn].buttState == 0   &&   board[cursorY][cursorX] == -1) {
    board[cursorY][cursorX] = playerTurn;
    playerTurn = !playerTurn;
    delay(200);
  }

  digitalWrite(player[0].ledPin, !playerTurn);
  digitalWrite(player[1].ledPin, playerTurn);

}

int Game::checkWin() {
  for ( int player = 0; player < 2; player++) {
    for (int row = 0; row < 3; row++) {
      if (board[0][row] == player  &&  board[1][row] == player && board[2][row] == player) {
        return player;
      }
    }

    for (int column = 0; column < 3; column++) {
      if (board[column][0] == player  &&  board[column][1] == player && board[column][2] == player) {
        return player;
      }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
      return player;
    }

    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
      return player;
    }
  }
  return -1;
}

bool Game::freePlace() {
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      // board[j][i] = -1;
      if ( board[j][i] == -1) {
        return true;
      }
    }
  }
  return false;
}

void Game::restart() {
  delay(5000);
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      board[j][i] = -1;
    }
  }
  playerTurn = 1;
  cursorX = 1;
  cursorY = 1;
  winner = -1;
  restartFlag = 0;
}