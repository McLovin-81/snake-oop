#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include "gameBoard.h"
#include "snake.cpp"
#include "input.cpp"


class GamePlay
{
    private:
        bool gameOver;

        GameBoard* board;

    public:
        GamePlay();
        void runDirection();
        void gameOverScreen();
        void collision();
        
        void gameLoop();
};

#endif // GAME_PLAY_H
