#include "gamePlay.h"


GamePlay::GamePlay()
{
    gameOver = false;
    board = new GameBoard();
}


void GamePlay::runDirection()
{
    Direction snakeDirection = board->getSnake()->getDirection();
    Direction snakeOldDirection = board->getSnake()->getOldDirection();
    
        if (board->getSnake()->getLength() > 1)
        {
            for (int i = board->getSnake()->getLength() - 1; i > 0; i--)
            {
                board->getSnake()->getCoordinateVector()[i] = board->getSnake()->getCoordinateVector()[i-1];
            }
        }

// TODO: Fix the other directions
    switch (snakeDirection)
    {



        case UP:
            if (snakeOldDirection == DOWN)
            {
                // board->getSnake()->setYposition(board->getSnake()->getYposition() +1); // DOWN
                board->getSnake()->getCoordinateVector()[0].second++;
            }
            else
            {
                //board->getSnake()->setYposition(board->getSnake()->getYposition() -1); // UP
                //board->getSnake()->setOldDirection(snakeDirection);

                board->getSnake()->getCoordinateVector()[0].second--;
                board->getSnake()->setOldDirection(snakeDirection);
            }
            break;
        case DOWN:
            if (snakeOldDirection == UP)
            {
                //board->getSnake()->setYposition(board->getSnake()->getYposition() -1); // UP
                board->getSnake()->getCoordinateVector()[0].second--;
            }
            else
            {
                //board->getSnake()->setYposition(board->getSnake()->getYposition() +1); // DOWN
                board->getSnake()->getCoordinateVector()[0].second++;
                board->getSnake()->setOldDirection(snakeDirection);
            }
            break;
        case RIGHT:
            if (snakeOldDirection == LEFT)
            {
                //board->getSnake()->setXposition(board->getSnake()->getXposition() -1); // LEFT
                board->getSnake()->getCoordinateVector()[0].first--;
            }
            else
            {
                //board->getSnake()->setXposition(board->getSnake()->getXposition() +1); // RIGHT
                board->getSnake()->getCoordinateVector()[0].first++;
                board->getSnake()->setOldDirection(snakeDirection);
            }
            break;
        case LEFT:
            if (snakeOldDirection == RIGHT)
            {
                //board->getSnake()->setXposition(board->getSnake()->getXposition() +1); // RIGHT
                board->getSnake()->getCoordinateVector()[0].first++;
            }
            else
            {
                //board->getSnake()->setXposition(board->getSnake()->getXposition() -1); // LEFT
                board->getSnake()->getCoordinateVector()[0].first--;
                board->getSnake()->setOldDirection(snakeDirection);
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


void GamePlay::collision()
{ // TODO: Dont need < 0 or < -1?
    // if (board->getSnake()->getXposition() <= 0 || board->getSnake()->getXposition() == board->getWidth() -1
    //    || board->getSnake()->getYposition() <= -1 || board->getSnake()->getYposition() == board->getHeight())
    if (board->getSnake()->getCoordinateVector()[0].first <= 0 || board->getSnake()->getCoordinateVector()[0].first == board->getWidth() -1
        || board->getSnake()->getCoordinateVector()[0].second <= -1 || board->getSnake()->getCoordinateVector()[0].second == board->getHeight())
    {
        gameOver = true;
    }
}


int GamePlay::getRandomNum(int range)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(2, range - 2); // Distribution from 2 to range - 2

    return dis(gen);
}


bool GamePlay::checkIfEaten()
{
    //if (board->getSnake()->getXposition() == board->getFruit()->getXposition() && board->getSnake()->getYposition() == board->getFruit()->getYposition())
    if (board->getSnake()->getCoordinateVector()[0].first == board->getFruit()->getXposition()
        && board->getSnake()->getCoordinateVector()[0].second == board->getFruit()->getYposition())
    {
        return true;
    }
    return false;
}


void GamePlay::doWhenEaten()
{
    board->getFruit()->setXposition(getRandomNum(board->getWidth()));
    board->getFruit()->setYposition(getRandomNum(board->getHeight()));

    board->increaseScore();

    board->getSnake()->setNewCoordinate(board->getSnake()->getCoordinateVector().back().first, board->getSnake()->getCoordinateVector().back().second);
}


void GamePlay::scoreScreen()
{
    std::cout << "-----------------\n";
    std::cout << "   Score: " << board->getScore() << "   \n";
    std::cout << "-----------------\n";
}


void GamePlay::gameLoop()
{
    while (!this->gameOver)
    {
        napms(500); // TODO: Put it in another place
        board->draw();
        Input::input(board->getSnake());
        runDirection();
        collision();
        if (checkIfEaten())
        {
            doWhenEaten();
        }
    }
    endwin(); // End ncurses mode from GameBord -> draw

    gameOverScreen();
    scoreScreen();
}
