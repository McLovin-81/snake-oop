#ifndef SNAKE_H
#define SNAKE_H


class Snake
{
    private:
        char design;
        int length;

        enum Direction {STOP, UP, DOWN, RIGTH, LEFT};
        Direction direction;

        // Possition. Is that correct here?
        int xPosition;
        int yPosition;


    public:
        Snake();
};


#endif // SNAKE_H
