#include "controller.h"


Controller::Controller()
{
    snake = new Snake();
    fruit = new Fruit();
    gameboard = new GameBoard();

    gameplay = new GamePlay();
    view = new View(fruit, gameboard);



    // snake->setNewCoordinate(gameboard->getWidth() / 2, gameboard->getHeight() / 2); // Start position
    snake->setNewCoordinate(0,0);
    // fruit->setCoordinate(gameplay->getRandomNum(gameboard->getWidth()), gameplay->getRandomNum(gameboard->getHeight())); // Start position
    fruit->setCoordinate(1, 0);
}


void Controller::gameLoop()
{
    // TEST -> if it works put it as a class variable
    float movementSpeed = 0.1f; // Adjust this value to control the speed of the snake. The higher the number the slower the movement
    float elapsedTime = 0.0f;

    while (!gameplay->getGameOver())
    {   
        view->drawObjects(snake, fruit, gameboard);
        gameplay->detectCollisionDelay(snake, gameboard);
        Input::input(snake);
        
        elapsedTime += GetFrameTime();
        if (elapsedTime >= movementSpeed)
        {
            gameplay->runDirection(snake);
            elapsedTime = 0.0f;
        }

        gameplay->collision(snake, gameboard);

        if (gameplay->checkIfEaten(snake, fruit))
        {
            gameplay->doWhenEaten(snake, fruit, gameboard);
        }
    }

    gameplay->gameOverScreen();
    gameplay->scoreScreen(gameboard);
}
