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
