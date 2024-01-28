#ifndef FRUIT_H
#define FRUIT_H


class Fruit
{
    private:
        char design;
        int xPosition;
        int yPosition;
    
    public:
        Fruit();
        char getDesign();
        void setXposition(int x);
        void setYposition(int y);
        int getXposition();
        int getYposition();
};


#endif // FRUIT_H
