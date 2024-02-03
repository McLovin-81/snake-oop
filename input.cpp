#include "input.h"

bool Input::inputPressed;

void Input::input(Snake* snake)
{
    char ch = getch();

    switch (ch)
    {
        case 'w':
            snake->setDirection(UP);
            inputPressed = true; // TODO:  DO i need this?
            break;
        case 's':
            snake->setDirection(DOWN);
            inputPressed = true;
            break;
        case 'd':
            snake->setDirection(RIGHT);
            inputPressed = true;
            break;
        case 'a':
            snake->setDirection(LEFT);
            inputPressed = true;
            break;
        default:
            inputPressed = false;
            break;
    }
}

bool Input::isInputPressed()
{
    return inputPressed;
}


void Input::setInputPressed(bool x)
{
    inputPressed = x;
}