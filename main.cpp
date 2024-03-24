#include "controller.cpp"


int main()
{
    Controller gameController;
    gameController.gameLoop();

    return 0;
}


// g++ -o main main.cpp -lraylib -I/opt/homebrew/Cellar/raylib/5.0/include -L/opt/homebrew/Cellar/raylib/5.0/lib -lpthread -std=c++20