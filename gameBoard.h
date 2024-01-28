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

        Snake* snake;
        Fruit* fruit;
    
    public:
        GameBoard();
        int getHeight();
        int getWidth();
        void draw();

        Snake* getSnake();
        Fruit* getFruit();
};

#endif // GAME_BOARD_H

