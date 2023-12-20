#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <ncurses.h>

class GameBoard
{
    private:
        int height;
        int width;
    
    public:
        GameBoard();
        int getHeight();
        int getWidth();

        void draw();
};

#endif // GAME_BOARD_H

