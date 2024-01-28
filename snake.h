#ifndef SNAKE_H
#define SNAKE_H


enum Direction {STOP, UP, DOWN, RIGHT, LEFT};

class Snake
{
    private:
        char design;
        int length;

        Direction direction;
        Direction oldDirection; // TODO: Test

        int xPosition;
        int yPosition;

    public:
        Snake();
        void setXposition(int x);
        void setYposition(int y);
        void setDirection(Direction direction);
        void setOldDirection(Direction direction); // TODO: Test

        Direction getDirection();
        Direction getOldDirection(); // TODO: Test
        int getXposition();
        int getYposition();

        char getDesign();
};


#endif // SNAKE_H
