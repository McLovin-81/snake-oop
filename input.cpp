#include "input.h"

void Input::input(Snake* snake)
{
    char ch = getch();
    std::cin >> ch;

        switch (ch)
    {
        case 'w':
            snake->setDirection(UP);
            break;
        case 's':
            snake->setDirection(DOWN);
            break;
        case 'd':
            snake->setDirection(LEFT);;
            break;
        case 'a':
            snake->setDirection(RIGTH);
        default:
            break;
    }

}