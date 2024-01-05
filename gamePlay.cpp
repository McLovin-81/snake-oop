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
    const int frameDelay = 50;
    while (!gameOver)
    {
        board->draw();
        Input::input(board->getSanke());
        logic();

        napms(frameDelay); // TODO: Delete
    }
    endwin(); // End ncurses mode from GameBord -> draw
}

void GamePlay::logic()
{
    Direction snakesDirection = board->getSanke()->getDirection();
///*
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
//*/
/*
    Direction snakesDirection = board->getSanke()->getDirection();

    int newX = board->getSanke()->getXposition();
    int newY = board->getSanke()->getYposition();

    // Update the snake's position based on the direction
    switch (snakesDirection)
    {
        case UP:
            newY--;
            break;
        case DOWN:
            newY++;
            break;
        case RIGHT:
            newX++;
            break;
        case LEFT:
            newX--;
            break;
        default:
            break;
    }

    // Set new position if within bounds
    if (newX >= 0 && newX < board->getWidth() && newY >= 0 && newY < board->getHeight())
    {
        board->getSanke()->setXposition(newX);
        board->getSanke()->setYposition(newY);
    }

*/

/*
    if (board->getSanke()->getXposition() <= 0 || board->getSanke()->getXposition() == board->getWidth() -1)
    {
        gameOver = true;
    }
*/
    if (board->getSanke()->getXposition() <= 0)
    {
        board->getSanke()->setXposition(24);
    }
}
