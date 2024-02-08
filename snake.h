#ifndef SNAKE_H
#define SNAKE_H

#include <vector>


enum Direction {STOP, UP, DOWN, RIGHT, LEFT};

class Snake
{
    private:
        char design;
        char bodyDesign; // TODO: Use the body design
        int length;

        Direction direction;
        Direction oldDirection;
        std::vector<std::pair<int, int> > coordinates;

    public:
        Snake();
        char getDesign();
        char getBodyDesign();
        int getLength();
        Direction getDirection();
        Direction getOldDirection();
        std::vector<std::pair<int, int> >& getCoordinateVector();
        void setDirection(Direction direction);
        void setOldDirection(Direction direction);
        void setNewCoordinate(int x, int y);

        void increaseLength();
};

#endif // SNAKE_H
