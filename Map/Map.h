#ifndef MAP_H
#define MAP_H

#include "../Land/Land.h"

class Map {
    public:
        Map(Player &player) {
            //Choose Map Size and Generate Map Layout
            ChooseMapSize();
            
            //!TEST mapsize; REMOVE
            std::cout << "Map Size X: " << map_X << std::endl
                      << "Map Size Y: " << map_Y << std::endl;
            
            //Create Map Array Using Size Parameters
            Land *map[map_X][map_Y];
            this->map = **&map;
            
            //Generate Lands on Map
            BuildMap(player);
        }
        
        //Print Map in ASCII Characters
        void Print();
    
    private:
        Land **map;
        
        unsigned int map_X;
        unsigned int map_Y;
        
        void ChooseMapSize();
        void BuildMap(Player &player);
};

#endif
