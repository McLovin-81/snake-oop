#include "gamePlay.h"

GamePlay::GamePlay()
{
    gameOver = false;
    score = 0;
}

bool GamePlay::getGameOver()
{
    return this->gameOver;
}

int GamePlay::getScore()
{
    return this->score;
}
