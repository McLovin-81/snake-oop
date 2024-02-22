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
}


void View::drawWindow()
{
    box(gameWindow, 0, 0); // Draw a box around the window
    wrefresh(gameWindow);
}


void View::clearWindow()
{
    wclear(gameWindow);
}


void View::drawObjects(Snake* snake, Fruit* fruit)
{
    napms(100); // TODO: Is this the correct place?

    for (auto coordinatePair : snake->getCoordinateVector())
    {
        mvwprintw(gameWindow, coordinatePair.second, coordinatePair.first, "%c", snake->getDesign());
    }

    mvwprintw(gameWindow, fruit->getCoordinate().second + 1, fruit->getCoordinate().first + 1, "%c", fruit->getDesign());

    wrefresh(gameWindow);
}
