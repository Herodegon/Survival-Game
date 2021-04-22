#ifndef MAP_H
#define MAP_H

#include "../Land/Land.h"
#include "../Entity/Character.h"

class Map {
    public:
        Map(Player &player) {
            //Choose Map Size and Generate Map Layout
            ChooseMapSize();
            
            /*!TEST mapsize; REMOVE
            std::cout << "Map Size X: " << map_X << std::endl
                      << "Map Size Y: " << map_Y << std::endl;
            */
            
            //Create Map Array Using Size Parameters
            map.resize(map_X);
            for(size_t i = 0; i < map_X; i++) {
                map[i].resize(map_Y);
            }
            
            //Generate Lands on Map
            BuildMap(player);
        }
        
        //Runs Main Turn
        void Turn(Player &player);
        
        //Access Function for Lands in Map
        Land* At(unsigned int x, unsigned int y) {return map[x][y];}
        
        //Move Character Across Map
        void Move(Character &_char, unsigned int dir);
        
        //Print Map in ASCII Characters
        void Print(Player &player);
    
    private:
        std::vector<std::vector<Land*>> map;
        
        unsigned int map_X;
        unsigned int map_Y;
        
        void ChooseMapSize();
        void BuildMap(Player &player);
};

#endif
