#include "fruit.h"


Fruit::Fruit()
{
    this->design = 'F';
    setXposition();
    setYposition();

    //gb = new GameBoard();
}


void Fruit::setXposition()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, gb->getWidth() -1); // replace the numbers with width min and witdh max

    this->xPosition = distrib(gen);
}


void Fruit::setYposition()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, gb->getHeight() -1); // replace the numbers with heigth min and heigth max

    this->yPosition = distrib(gen);
}


int Fruit::getXposition()
{
    return this-> xPosition;
}


int Fruit::getYposition()
{
    return this-> yPosition;
}
