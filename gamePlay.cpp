#include "gamePlay.h"

GamePlay::GamePlay()
{
    gameOver = false;
    score = 0;

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
    }
    endwin(); // End ncurses mode from GameBord -> draw
}
