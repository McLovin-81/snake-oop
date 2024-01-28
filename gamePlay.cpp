#include "gamePlay.h"


GamePlay::GamePlay()
{
    gameOver = false;
    score = 0;
    frameDelay = 300;
    board = new GameBoard();
}


bool GamePlay::getGameOver()
{
    return this->gameOver;
}


int GamePlay::getScore()
{
    return this->score;
}


void GamePlay::runDirection()
{
    Direction snakeDirection = board->getSnake()->getDirection();
    Direction snakeOldDirection = board->getSnake()->getOldDirection();
    napms(frameDelay); // TODO: Put it in another place

    switch (snakeDirection)
    {
        case UP:
            board->getSnake()->setYposition(board->getSnake()->getYposition() -1); // refator this mess
            break;
        case DOWN:
            board->getSnake()->setYposition(board->getSnake()->getYposition() +1);
            break;
        case RIGHT:
            board->getSnake()->setXposition(board->getSnake()->getXposition() +1);
            break;
        case LEFT:
            board->getSnake()->setXposition(board->getSnake()->getXposition() -1);
        default:
            break;
    }
}


void GamePlay::collision()
{
    if (board->getSnake()->getXposition() <= 0 || board->getSnake()->getXposition() == board->getWidth() -1
        || board->getSnake()->getYposition() <= -1 || board->getSnake()->getYposition() == board->getHeight())
    {
        gameOver = true;
    }
}


void GamePlay::gameOverScreen()
{
    std::cout << "-----------------\n";
    std::cout << "|   Game Over   |\n";
    std::cout << "-----------------\n";
}


void GamePlay::gameLoop()
{
    while (!this->gameOver)
    {
        board->draw();
        Input::input(board->getSnake());
        runDirection();
        collision();
    }
    endwin(); // End ncurses mode from GameBord -> draw

    gameOverScreen();
}
