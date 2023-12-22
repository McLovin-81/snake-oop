#include "snake.h"

Snake::Snake()
{
    design = 'O';
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

void Snake::setDirection(Direction direction)
{
    this->direction = direction;
}

Direction Snake::getDirection()
{
    return this->direction;
}

int Snake::getXposition()
{
    return this->xPosition;
}

int Snake::getYposition()
{
    return this->yPosition;
}

char Snake::getDesign()
{
    return design;
}