#include "gameBoard.h"


GameBoard::GameBoard()
{
    width = 50;
    height = 30;
    score = 0;

    snake = new Snake();
    fruit = new Fruit();
    //snake->setXposition(width / 2); // Start position
    //snake->setYposition(height / 2); // Start position
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

            // Print snake
            //else if (i == snake->getYposition() && j == snake->getXposition())
            else if (i == snake->getCoordinateVector()[snake->getLength() -1].second && j == snake->getCoordinateVector()[snake->getLength() -1].first)
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
