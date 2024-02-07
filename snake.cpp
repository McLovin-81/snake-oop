#include "snake.h"


Snake::Snake()
{
    design = 'O';
    length = 0; // TODO: need to increase during the code is running
    direction = STOP;
    oldDirection = STOP;
}

/*
void Snake::setXposition(int x)
{
    this->xPosition = x;
}


void Snake::setYposition(int y)
{
    this->yPosition = y;
}
*/


void Snake::setDirection(Direction direction)
{
    this->direction = direction;
}


void Snake::setOldDirection(Direction direction)
{
    this->oldDirection = direction;
}


Direction Snake::getDirection()
{
    return this->direction;
}


Direction Snake::getOldDirection()
{
    return this->oldDirection;
}

/*
int Snake::getXposition()
{
    return this->xPosition;
}

int Snake::getYposition()
{
    return this->yPosition;
}
*/

char Snake::getDesign()
{
    return design;
}


void Snake::setCoordinate(int x, int y)
{
    coordinates.push_back(std::make_pair(x, y));
}


std::vector<std::pair<int, int> >& Snake::getCoordinateVector()
{
    return this->coordinates;
}


void Snake::increaseLength()
{
    this->length += 1;
}

