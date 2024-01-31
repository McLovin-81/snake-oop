#include "gameBoard.h"


GameBoard::GameBoard()
{
    width = 25;
    height = 15;

    snake = new Snake();
    fruit = new Fruit();
    snake->setXposition(width / 2);
    snake->setYposition(height / 2);
    fruit->setXposition(3);
    fruit->setYposition(3);
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
            // Print snake head
            else if (i == snake->getYposition() && j == snake->getXposition())
            {
                printw("%c", snake->getDesign()); // "%c" -> Indicate that the corresponding argument should be interpreted as a character.
            }
            // Print Fruit
            else if (i == fruit->getYposition() && j == fruit->getXposition())
            {
                printw("%c", fruit->getDesign());
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

    // Print some information. Can be deleted later
    printw("Direction: %d, Old direction: %d", snake->getDirection(), snake->getOldDirection()); // TODO: Delete
    printw("\n"); // TODO: Delete
    printw("X position: %d, Y position: %d", getSnake()->getXposition(), getSnake()->getYposition()); // TODO: Delete
}


Snake* GameBoard::getSnake()
{
    return this->snake;
}


Fruit* GameBoard::getFruit()
{
    return this->fruit;
}
