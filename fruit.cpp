#include "fruit.h"


Fruit::Fruit()
{
    this->design = 'F';
}


void Fruit::setXposition(int x)
{
    this->xPosition = x;
}


void Fruit::setYposition(int y)
{
    this->yPosition = y;
}


int Fruit::getXposition()
{
    return this-> xPosition;
}


int Fruit::getYposition()
{
    return this-> yPosition;
}


char Fruit::getDesign()
{
    return this->design;
}
