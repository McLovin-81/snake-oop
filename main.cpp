#include <iostream>
#include <ncurses.h>

#include "gameBoard.cpp" // TODO: Why do i need this include?
#include "gamePlay.cpp"


int main()
{
    GamePlay* gamePlay = new GamePlay();

    gamePlay->gameLoop();

    return 0;
}

// Can i make a container class with all the diferents objects from all clases.