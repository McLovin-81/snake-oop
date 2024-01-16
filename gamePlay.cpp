#include "gamePlay.h"


GamePlay::GamePlay()
{
    gameOver = false;
    score = 0;
    frameDelay = 100;
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


void GamePlay::gameLoop()
{
    while (!gameOver)
    {
        board->draw();
        Input::input(board->getSanke());
        runDirection();
        collision();
    }
    endwin(); // End ncurses mode from GameBord -> draw

    gameOverScreen();
}


void GamePlay::runDirection()
{
    Direction snakesDirection = board->getSanke()->getDirection();
    napms(frameDelay); // TODO: Put it in another place

    switch (snakesDirection)
    {
        case UP:
            board->getSanke()->setYposition(board->getSanke()->getYposition() -1); // refator this mess
            break;
        case DOWN:
            board->getSanke()->setYposition(board->getSanke()->getYposition() +1);
            break;
        case RIGHT:
            board->getSanke()->setXposition(board->getSanke()->getXposition() +1);
            break;
        case LEFT:
            board->getSanke()->setXposition(board->getSanke()->getXposition() -1);
        default:
            break;
    }
}


void GamePlay::collision()
{
    if (board->getSanke()->getXposition() <= 0 || board->getSanke()->getXposition() == board->getWidth() -1
        || board->getSanke()->getYposition() <= -1 || board->getSanke()->getYposition() == board->getHeight())
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
