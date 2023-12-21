#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include "gameBoard.h"
#include "snake.h"

class GamePlay
{
    private:
        bool gameOver;
        int score;

        GameBoard board;
        Snake snake;

    public:
        GamePlay();
        bool getGameOver();
        int getScore();
        void gameLoop();
        void setSnakeInitPosition();
};

#endif // GAME_PLAY_H
