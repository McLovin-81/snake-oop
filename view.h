#ifndef VIEW_H
#define VIEW_H

#include <ncurses.h>

#include "snake.h" // Why is this needed?
#include "fruit.h" // Why is this needed?

class View
{
    private:
    public:
        void draw(GameBoard* gameBoard, Snake* snake, Fruit* fruit);

};


#endif // VIEW_H
