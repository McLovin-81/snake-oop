#include "view.h"


View::View(Fruit* fruit, GameBoard* gameBoard)
{
    cellSize = 30;

    // Window is 2 * cellZise bigger than the gameboard.
    InitWindow(gameBoard->getHeight() * cellSize + cellSize * 2, gameBoard->getWidth() * cellSize + cellSize * 2, "Snake Game");
    SetTargetFPS(60);
    
    image = LoadImage("graphics/food.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}


void View::drawObjects(Snake* snake, Fruit* fruit, GameBoard* gameBoard)
{
    BeginDrawing();
    ClearBackground(green);

    // Draw snake
    Rectangle segment;
    for (auto coordinatePair : snake->getCoordinateVector())
    {
        segment = Rectangle{(float)coordinatePair.first * cellSize + cellSize, (float)coordinatePair.second * cellSize + cellSize, (float)cellSize, (float)cellSize};
        DrawRectangleRounded(segment, 0.5, 6, BLUE);
    }

    // Draw board
    segment = Rectangle{(float)cellSize, (float)cellSize, (float)gameBoard->getWidth() * cellSize, (float)gameBoard->getHeight() * cellSize};
    DrawRectangleLinesEx(segment, 1, BLACK);

    // Draw fruit
    DrawTexture(texture, fruit->getCoordinate().first * cellSize + cellSize, fruit->getCoordinate().second * cellSize + cellSize, WHITE);

    EndDrawing();
}


View::~View()
{
    UnloadTexture(texture);
}
