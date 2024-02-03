#ifndef INPUT_H
#define INPUT_H

#include "gameBoard.h"

#include <iostream>


class Input
{
    private:
        static bool inputPressed;
    public:
       static void input(Snake* snake);
       static bool isInputPressed();
       static void setInputPressed(bool x);
};


#endif // INPUT_H