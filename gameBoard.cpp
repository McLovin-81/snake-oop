#include "gameBoard.h"


GameBoard::GameBoard()
{
    width = 60;
    height = 20;
    score = 0;
<<<<<<< HEAD

    snake = new Snake();
    fruit = new Fruit();
    snake->setNewCoordinate(width / 2, height / 2);
    snake->increaseLength();
    fruit->setCoordinate(width - 5, height - 3); // Start position | TODO: Need random number
=======
>>>>>>> separateGraphics
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


void GameBoard::increaseScore()
{
    this->score += 10;
}
