#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.cpp"
#include "fruit.cpp"
#include "gameBoard.cpp"

#include "gamePlay.cpp"
#include "input.cpp"
#include "view.cpp"

class Controller
{
private:
    Snake* snake;
    Fruit* fruit;
    GameBoard* gameboard;

    GamePlay* gameplay;
    //Input* input;
    View* view;

public:
    Controller();
    void gameLoop();
};

#endif // CONTROLLER_H
