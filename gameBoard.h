#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <ncurses.h>
#include "snake.h"

class GameBoard
{
    private:
        int height;
        int width;

        Snake* snake;
    
    public:
        GameBoard();
        int getHeight();
        int getWidth();

        void draw();
};

#endif // GAME_BOARD_H

