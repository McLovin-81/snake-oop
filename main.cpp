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

/*
TODO:
If the snake has always the same start point and the snakes knows the parameter width and heigth
i dont need to print the board in a loop -> just the snakes position?*/