#include "view.h"


View::View()
{
    initscr();
    noecho();
    nodelay(stdscr, true); // Make getch non-blocking
    curs_set(0); // Hide the cursor
    // keypad(stdscr, TRUE); // Enable special keys (e.g., arrow keys) -> KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
}


void View::createWindow(GameBoard* gameBoard)
{
    this->gameWindow = newwin(gameBoard->getHeight(), gameBoard->getWidth(), 0, 0); // Create the game window

    this->hubWindow = newwin(5, gameBoard->getWidth(), gameBoard->getHeight(), 0);
}


void View::drawWindow()
{
    box(gameWindow, 0, 0); // Draw a box around the window
    box(hubWindow, 0, 0);
    wrefresh(gameWindow);
    wrefresh(hubWindow);
}


void View::clearWindow()
{
    wclear(gameWindow);
    wclear(hubWindow);
}


void View::drawObjects(Snake* snake, Fruit* fruit, GameBoard* gameBoard)
{
    napms(80); // TODO: Is this the correct place?

    for (auto coordinatePair : snake->getCoordinateVector())
    {
        mvwprintw(gameWindow, coordinatePair.second, coordinatePair.first, "%c", snake->getDesign());
    }

    mvwprintw(gameWindow, fruit->getCoordinate().second, fruit->getCoordinate().first, "%c", fruit->getDesign());

    mvwprintw(hubWindow, 1, 1, "SCORE: %d", gameBoard->getScore());

    wrefresh(gameWindow);
    wrefresh(hubWindow);
}
