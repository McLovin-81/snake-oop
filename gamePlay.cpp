#include "gamePlay.h"


GamePlay::GamePlay()
{
    gameOver = false;
    score = 0;
    frameDelay = 150;
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
        logic();
    }
    endwin(); // End ncurses mode from GameBord -> draw
}


void GamePlay::logic()
{
    Direction snakesDirection = board->getSanke()->getDirection();
    napms(frameDelay); // TODO: Delete

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

    if (board->getSanke()->getXposition() <= 0 || board->getSanke()->getXposition() == board->getWidth() -1)
    {
        gameOver = true;
    }

}
