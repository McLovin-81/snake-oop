#include "gamePlay.h"


GamePlay::GamePlay()
{
    gameOver = false;
}


void GamePlay::runDirection(Snake* snake)
{
    Direction snakeDirection = snake->getDirection();
    Direction snakeOldDirection = snake->getOldDirection();
    
    if (snake->getLength() > 1)
    {
        for (int i = snake->getLength() - 1; i > 0; i--)
        {
            snake->getCoordinateVector()[i] = snake->getCoordinateVector()[i-1];
        }
    }

    switch (snakeDirection)
    {
        case UP:
            if (snakeOldDirection == DOWN)
            {
                snake->getCoordinateVector()[0].second++;
            }
            else
            {
                snake->getCoordinateVector()[0].second--;
                snake->setOldDirection(snakeDirection);
            }
            break;
        case DOWN:
            if (snakeOldDirection == UP)
            {
                snake->getCoordinateVector()[0].second--;
            }
            else
            {
                snake->getCoordinateVector()[0].second++;
                snake->setOldDirection(snakeDirection);
            }
            break;
        case RIGHT:
            if (snakeOldDirection == LEFT)
            {
                snake->getCoordinateVector()[0].first--;
            }
            else
            {
                snake->getCoordinateVector()[0].first++;
                snake->setOldDirection(snakeDirection);
            }
            break;
        case LEFT:
            if (snakeOldDirection == RIGHT)
            {
                snake->getCoordinateVector()[0].first++;
            }
            else
            {
                snake->getCoordinateVector()[0].first--;
                snake->setOldDirection(snakeDirection);
            }
        default:
            break;
    }
}


void GamePlay::gameOverScreen()
{
    std::cout << "-----------------\n";
    std::cout << "|   Game Over   |\n";
    std::cout << "-----------------\n";
}


// TODO: No more working!
void GamePlay::detectCollisionDelay(Snake* snake, GameBoard* gameBoard)
{
    std::vector<std::pair<int, int> > coordinates = snake->getCoordinateVector();
    std::pair<int, int> snakeHead = snake->getCoordinateVector()[0];
    Direction snakeDirection = snake->getDirection();
    int snakeLength = snake->getLength();

    if ((snakeHead.first == 1 && snakeDirection == LEFT) || (snakeHead.first == gameBoard->getWidth() -2 && snakeDirection == RIGHT)||
        (snakeHead.second == 1 && snakeDirection == UP)|| (snakeHead.second == gameBoard->getHeight() -2 && snakeDirection == DOWN))
    {
        // napms(150); OLD
    }

/*
    if (snakeLength >= 5)
    {
        for (int i = 4; i < snakeLength -1; i++)
        {
            if ((snakeHead.first == coordinates[i].first -1  && snakeDirection == LEFT) || snakeHead.first == coordinates[i].first +1 && snakeDirection == RIGHT)
            {
                napms(150);
            }
        }
    }
*/
}


void GamePlay::collision(Snake* snake, GameBoard* gameBoard)
{
    std::vector<std::pair<int, int> > coordinates = snake->getCoordinateVector();
    std::pair<int, int> snakeHead = snake->getCoordinateVector()[0];
    int snakeLength = snake->getLength();

    // Agains walls
    if (snakeHead.first == -1 || snakeHead.first == gameBoard->getWidth() || snakeHead.second == -1 || snakeHead.second == gameBoard->getHeight())
    {
        gameOver = true;
    }

    // Agains body
    for (int i = 1; i < snakeLength -1; i++)
    {
        if (snakeHead == coordinates[i])
        {
            gameOver = true;
            break;
        }
    }
}


int GamePlay::getRandomNum(int range)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(2, range - 2); // Distribution from 2 to range - 2

    return dis(gen);
}


bool GamePlay::checkIfEaten(Snake* snake, Fruit* fruit)
{
    if (snake->getCoordinateVector()[0].first == fruit->getCoordinate().first
            && snake->getCoordinateVector()[0].second == fruit->getCoordinate().second)
    {
        return true;
    }
    return false;
}


void GamePlay::doWhenEaten(Snake* snake, Fruit* fruit, GameBoard* gameBoard)
{
    // Check that the fruit position does not overlap with a snake position
    bool fruitPositionOk = false;
    int fruitXPosition;
    int fruitYPosition;

    while (!fruitPositionOk)
    {
        fruitXPosition = getRandomNum(gameBoard->getWidth());
        fruitYPosition = getRandomNum(gameBoard->getHeight());

        fruitPositionOk = true; // Assume the position is ok until we find an overlap

        for (auto coordinatePair : snake->getCoordinateVector())
        {
            if (fruitXPosition == coordinatePair.first && fruitYPosition == coordinatePair.second)
            {
                fruitPositionOk = false; // Overlap found, set fruitPositionOk to false
                break;
            }
        }
    }
    
    // Set the fruit's coordinate after ensuring it doesn't overlap with the snake
    fruit->setCoordinate(fruitXPosition, fruitYPosition);

    gameBoard->increaseScore();

    snake->setNewCoordinate(snake->getCoordinateVector().back().first, snake->getCoordinateVector().back().second);
}


void GamePlay::scoreScreen(GameBoard* gameBoard)
{
    std::cout << "-----------------\n";
    std::cout << "   Score: " << gameBoard->getScore() << "   \n";
    std::cout << "-----------------\n";
}


bool GamePlay::getGameOver()
{
    return this->gameOver;
}
