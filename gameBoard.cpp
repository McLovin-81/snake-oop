#include "gameBoard.h"


GameBoard::GameBoard()
{
    width = 60;
    height = 20;
    score = 0;

    snake = new Snake();
    fruit = new Fruit();
    snake->setNewCoordinate(width / 2, height / 2);
    fruit->setXposition(width - 5); // Start position | TODO: Need random number
    fruit->setYposition(height - 3); // Start position | TODO: Need random number
}


int GameBoard::getHeight()
{
    return this->height;
}


int GameBoard::getWidth()
{
    return this->width;
}


int GameBoard::getScore()
{
    return this->score;
}


Snake* GameBoard::getSnake()
{
    return this->snake;
}


Fruit* GameBoard::getFruit()
{
    return this->fruit;
}


void GameBoard::increaseScore()
{
    this->score += 10;
}


void GameBoard::draw()
{
    clear();
    initscr();
    noecho();
    nodelay(stdscr, true); // Make getch non-blocking
    bool snakeFound;
    bool fruitPrinted;

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
                snakeFound = false;
                fruitPrinted = false;

                for (auto coordinate : snake->getCoordinateVector())
                {
                    if (coordinate.first == j && coordinate.second == i)
                    {
                        printw("%c", snake->getDesign());
                        snakeFound = true;
                        break;
                    }
                }

                if (i == fruit->getYposition() && j == fruit->getXposition())
                {
                    printw("%c", fruit->getDesign());
                    fruitPrinted = true;
                }

                if (!snakeFound && !fruitPrinted)
                {
                    printw(" ");
                }
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

    printw("Score: %d", this->score);
    printw("\n");

    // Print some information. Can be deleted later
    printw("Direction: %d, Old direction: %d", snake->getDirection(), snake->getOldDirection()); // TODO: Delete
    printw("\n"); // TODO: Delete
    printw("Snake length: %d", snake->getLength()); // TODO: Delete
    printw("\n"); // TODO: Delete

    for (auto coordinatePair : snake->getCoordinateVector())
    {
        printw("(%d, %d)", coordinatePair.first, coordinatePair.second);
    }
}
