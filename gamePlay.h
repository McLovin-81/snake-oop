#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include <random>

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
        void detectCollisionDelay();
        void collision();
        int getRandomNum(int range);
        bool checkIfEaten();
        void doWhenEaten();
        void scoreScreen();
        
        void gameLoop();
};

#endif // GAME_PLAY_H
