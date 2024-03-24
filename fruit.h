#ifndef FRUIT_H
#define FRUIT_H

#include <utility>
#include <string>

class Fruit
{
    private:
        char design;
        // const char* texture;
        std::pair<int, int> coordinate;
    
    public:
        Fruit();
        char getDesign();
        std::pair<int, int> getCoordinate();
        void setCoordinate(int x, int y);
        // const char* getTexture();
};


#endif // FRUIT_H
