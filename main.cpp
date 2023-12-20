#include <iostream>
#include <ncurses.h>

#include "gameBoard.cpp"
#include "gamePlay.cpp"


int main()
{
    GameBoard board;
    GamePlay gamePlay;

    while (!gamePlay.getGameOver())
    {
        clear(); // Clear the screen
        board.draw();
    }
    

    endwin(); // End ncurses mode
    return 0;
}
