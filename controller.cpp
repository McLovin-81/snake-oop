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
    view->createWindow(gameboard);
    
    while(!gameplay->getGameOver())
    {
        view->clearWindow();
        view->drawObjects(snake, fruit);
        view->drawWindow();
        
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
