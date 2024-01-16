#ifndef FRUIT_H
#define FRUIT_H

#include "gameBoard.h" // Needed to get the width and heigth 
#include <random>


class Fruit
{
    private:
        char design;
        int xPosition;
        int yPosition;
        // GameBoard* gb;
    
    public:
        Fruit();
        void setXposition();
        void setYposition();
        int getXposition();
        int getYposition();
};


#endif // FRUIT_H
