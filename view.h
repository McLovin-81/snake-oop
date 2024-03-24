#ifndef VIEW_H
#define VIEW_H


#include <raylib.h>

#include "snake.h" // Why is this needed?
#include "fruit.h" // Why is this needed?
#include "gameBoard.h"


Color green = {173, 204, 96, 255};

class View
{
    private:
        int cellSize;
        int cellCount; // TODO: Do i need this?

        Image image;
        Texture2D texture;

    public:
        View(Fruit* fruit, GameBoard* gameBoard);
        void drawObjects(Snake* snake, Fruit* fruit, GameBoard* gameBoard);
        ~View();
};

#endif // VIEW_H
