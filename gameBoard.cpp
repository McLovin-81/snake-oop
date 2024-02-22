#include "gameBoard.h"


GameBoard::GameBoard()
{
    width = 30;
    height = 10;
    score = 0;
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
