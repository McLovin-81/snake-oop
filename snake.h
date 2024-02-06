#ifndef SNAKE_H
#define SNAKE_H


enum Direction {STOP, UP, DOWN, RIGHT, LEFT};

class Snake
{
    private:
        char design;
        int length;

        Direction direction;
        Direction oldDirection;

        int xPosition; // Change to vector
        int yPosition; // Change to vector

    public:
        Snake();
        void setXposition(int x);
        void setYposition(int y);
        void setDirection(Direction direction);
        void setOldDirection(Direction direction);

        Direction getDirection();
        Direction getOldDirection();
        int getXposition();
        int getYposition();
        char getDesign();
};


#endif // SNAKE_H
