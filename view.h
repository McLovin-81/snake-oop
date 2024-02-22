#ifndef VIEW_H
#define VIEW_H

#include <ncurses.h>

#include "snake.h" // Why is this needed?
#include "fruit.h" // Why is this needed?

class View
{
    private:
        WINDOW* gameWindow;
        WINDOW* hubWindow;
    public:
        View();
        void createWindow(GameBoard* gameBoard);
        void drawWindow();
        void drawObjects(Snake* snake, Fruit* fruit, GameBoard* gameBoard);
        void clearWindow();


};


#endif // VIEW_H
