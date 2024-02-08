#ifndef FRUIT_H
#define FRUIT_H


class Fruit
{
    private:
        char design;
        int xPosition; // TODO: Change to pair
        int yPosition; // TODO: Change to pair
    
    public:
        Fruit();
        char getDesign();
        int getXposition();
        int getYposition();
        void setXposition(int x);
        void setYposition(int y);
};


#endif // FRUIT_H
