#ifndef MAP_H
#define MAP_H

#include "../Land/Land.cpp"

class Map {
    public:
        Map();
        Map(unsigned int x, unsigned int y) {
            
        }
        
        void Print();
    
    private:
        Land *map;
    
        unsigned int map_x;
        unsigned int map_y;
};

#endif
