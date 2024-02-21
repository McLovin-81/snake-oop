#include "view.h"


void View::draw(GameBoard* gameBoard, Snake* snake, Fruit* fruit)
{
    clear();
    initscr();
    noecho();
    nodelay(stdscr, true); // Make getch non-blocking

    napms(80); // TODO: Is this the correct place?

    bool snakeFound;
    bool fruitPrinted;
    bool snakeHead = true;

    for (int i = 0; i < gameBoard->getWidth(); i++)
    {
        printw("#");
    }

    printw("\n");

    for (int i = 0; i < gameBoard->getHeight(); i++)
    {
        for (int j = 0; j < gameBoard->getWidth(); j++)
        {
            if (j == 0 || j == gameBoard->getWidth() -1)
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
                        if (snakeHead == true)
                        {
                            printw("%c", snake->getDesign());
                            snakeHead = false;
                        }
                        else
                        {
                            printw("%c", snake->getBodyDesign());
                        }
                        snakeFound = true;
                        break;
                    }
                }

                if (i == fruit->getCoordinate().second && j == fruit->getCoordinate().first)
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

        for (int i = 0; i < gameBoard->getWidth(); i++)
        {
            printw("#");
        }

        printw("\n");

        refresh(); // Refresh the screen

        printw("Score: %d", gameBoard->getScore());
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
