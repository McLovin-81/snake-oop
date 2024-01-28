#include "gameBoard.cpp" // TODO: Why do i need this include?
#include "gamePlay.cpp"


int main()
{
    GamePlay* gamePlay = new GamePlay();

    gamePlay->gameLoop();

    return 0;
}
