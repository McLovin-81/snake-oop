#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <ncurses.h>

#include "snake.h"
#include "fruit.h"

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

        Snake* getSanke();
};

#endif // GAME_BOARD_H

