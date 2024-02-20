#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include <random>
#include <iostream>

#include "ncurses.h" // Needed to napms()

class GamePlay
{
    private:
        bool gameOver;

    public:
        GamePlay();
        void runDirection(Snake* snake);
        void gameOverScreen();
        void detectCollisionDelay(Snake* snake, GameBoard* gameBoard);
        void collision(Snake* snake, GameBoard* gameBoard);
        int getRandomNum(int range);
        bool checkIfEaten(Snake* snake, Fruit* fruit);
        void doWhenEaten(Snake* snake, Fruit* fruit, GameBoard* gameBoard);
        void scoreScreen(GameBoard* gameBoard);
        bool getGameOver();
};

#endif // GAME_PLAY_H
