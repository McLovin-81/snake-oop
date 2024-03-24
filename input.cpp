#include "input.h"


void Input::input(Snake* snake)
{
   // Check for key presses using Raylib
    if (IsKeyDown(KEY_W))
    {
        snake->setDirection(UP);
    }
    else if (IsKeyDown(KEY_S))
    {
        snake->setDirection(DOWN);
    }
    else if (IsKeyDown(KEY_D))
    {
        snake->setDirection(RIGHT);
    }
    else if (IsKeyDown(KEY_A))
    {
        snake->setDirection(LEFT);
    }
    else if (IsKeyDown(KEY_P))
    {
        snake->setDirection(STOP);
    }
}
