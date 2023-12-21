#include "gameBoard.h"

#include <iostream>


GameBoard::GameBoard()
{
    width = 25;
    height = 15;
}

int GameBoard::getHeight()
{
    return this->height;
}

int GameBoard::getWidth()
{
    return this->width;
}

void GameBoard::draw()
{
    clear();
    initscr();
    noecho();
    nodelay(stdscr, true); // Make getch non-blocking

    for (int i = 0; i < width; i++)
    {
        printw("#");
    }

    printw("\n");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width -1)
            {
                printw("#");
            }
            else
            {
                printw(" ");
            }
        }
        printw("\n");
    }

    for (int i = 0; i < width; i++)
    {
        printw("#");
    }

    printw("\n");

    refresh(); // Refresh the screen
    //getch();   // Wait for user input -> where do i need this?
}
