#include "gamePlay.h"

GamePlay::GamePlay()
{
    gameOver = false;
    score = 0;

    board = new GameBoard();
    snake = new Snake();
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
    setSnakeInitPosition();
    while (!gameOver)
    {
        board->draw();
    }
    endwin(); // End ncurses mode from GameBord -> draw
}

void GamePlay::setSnakeInitPosition()
{
    snake->setXposition(board->getWidth() / 2);
    snake->setYposition(board->getHeight() / 2);
}
