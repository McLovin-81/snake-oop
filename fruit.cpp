#include "fruit.h"


Fruit::Fruit()
{
    this->design = 'F';
    // this->texture = "graphics/food.png";
}


std::pair<int, int> Fruit::getCoordinate()
{
    return this->coordinate;
}


char Fruit::getDesign()
{
    return this->design;
}


void Fruit::setCoordinate(int x, int y)
{
    this->coordinate = std::make_pair(x, y);
}

/*
const char* Fruit::getTexture()
{
    return this->texture;
}
*/