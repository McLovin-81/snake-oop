#ifndef SNAKE_H
#define SNAKE_H

#include <vector>


enum Direction {STOP, UP, DOWN, RIGHT, LEFT};

class Snake
{
    private:
        char design;
        int length;

        Direction direction;
        Direction oldDirection;

        //int xPosition; // Change to vector
        //int yPosition; // Change to vector

        std::vector<std::pair<int, int> > coordinates;

    public:
        Snake();
        //void setXposition(int x);
        //void setYposition(int y);

        void setDirection(Direction direction);
        void setOldDirection(Direction direction);

        Direction getDirection();
        Direction getOldDirection();

        //int getXposition();
        //int getYposition();
        
        char getDesign();

        void setNewCoordinate(int x, int y);
        std::vector<std::pair<int, int> >& getCoordinateVector();
        int getLength();
        void increaseLength();
};


#endif // SNAKE_H
