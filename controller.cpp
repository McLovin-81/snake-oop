#include "controller.h"


Controller::Controller()
{
    snake = new Snake();
    fruit = new Fruit();
    gameboard = new GameBoard();

    gameplay = new GamePlay();
    view = new View();

    snake->setNewCoordinate(gameboard->getWidth() / 2, gameboard->getHeight() / 2);
    fruit->setCoordinate(gameplay->getRandomNum(gameboard->getWidth()), gameplay->getRandomNum(gameboard->getHeight())); // Start position | TODO: Need random number
}


void Controller::gameLoop()
{
    while(!gameplay->getGameOver())
    {
        view->draw(gameboard, snake, fruit);
        gameplay->detectCollisionDelay(snake, gameboard);
        Input::input(snake);
        gameplay->runDirection(snake);
        gameplay->collision(snake, gameboard);

        if (gameplay->checkIfEaten(snake, fruit))
        {
            gameplay->doWhenEaten(snake, fruit, gameboard);
        }
    }

    endwin();
    gameplay->gameOverScreen();
    gameplay->scoreScreen(gameboard);
}
