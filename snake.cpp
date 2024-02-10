#include "snake.h"


Snake::Snake()
{
    design = 'O';
    bodyDesign = 'o';
    length = 0;
    direction = STOP;
    oldDirection = STOP;
}


char Snake::getBodyDesign()
{
    return this->bodyDesign;
}


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


char Snake::getDesign()
{
    return design;
}


void Snake::setNewCoordinate(int x, int y)
{
    coordinates.push_back(std::make_pair(x, y));
    //increaseLength();
}


std::vector<std::pair<int, int> >& Snake::getCoordinateVector()
{
    return this->coordinates;
}


void Snake::increaseLength()
{
    this->length += 1;
}


int Snake::getLength()
{
    return this->length;
}
