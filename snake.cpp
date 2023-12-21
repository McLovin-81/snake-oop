#include "snake.h"

Snake::Snake()
{
    length = 1;
    direction = STOP;
}


void Snake::setXposition(int x)
{
    this->xPosition = x;
}

void Snake::setYposition(int y)
{
    this->yPosition = y;
}


int Snake::getXposition()
{
    return this->xPosition;
}

int Snake::getYposition()
{
    return this->yPosition;
}

char Snake::getDesign() const
{
    return design;
}