#ifndef FRUIT_H
#define FRUIT_H

#include <utility>

class Fruit
{
    private:
        char design;
        std::pair<int, int> coordinate;
    
    public:
        Fruit();
        char getDesign();
        std::pair<int, int> getCoordinate();
        void setCoordinate(int x, int y);
};


#endif // FRUIT_H
