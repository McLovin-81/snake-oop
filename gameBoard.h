#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <ncurses.h>

#include "snake.h"
#include "fruit.cpp"


class GameBoard
{
    private:
        int height;
        int width;
        int score;

        Snake* snake;
        Fruit* fruit;
    
    public:
        GameBoard();
        int getHeight();
        int getWidth();
        int getScore();
        Snake* getSnake();
        Fruit* getFruit();
        void increaseScore();
        void draw();
};

#endif // GAME_BOARD_H
