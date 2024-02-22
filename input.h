#ifndef INPUT_H
#define INPUT_H

#include "ncurses.h" // Needed to use getch()


class Input
{
    private:

    public:
       static void input(Snake* snake);
};

#endif // INPUT_H