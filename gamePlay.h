#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include "gameBoard.h"
#include "snake.cpp"
#include "input.cpp"

class GamePlay
{
    private:
        bool gameOver;
        int score;

        GameBoard* board;

    public:
        GamePlay();
        bool getGameOver();
        int getScore();
        void gameLoop();
};

#endif // GAME_PLAY_H
