#include "gameBoard.h"


GameBoard::GameBoard()
{
    width = 60;
    height = 20;
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
