#include "Land.h"

Land* BuildMap(size_t MAP_SIZE_X = 20, size_t MAP_SIZE_Y = 20} {
    Land* map = new Land[MAP_SIZE_X][MAP_SIZE_Y];
    
    for(size_t i = 0; i < MAP_SIZE_Y; i++) {
        for(size_t k = 0; k < MAP_SIZE_X; k++) {
            if(

Land* getRandomLand() {
    srand(time(NULL));
    LandTypes selection = rand() % MAX_LAND_TYPES;
    
    switch(selection) {
        case 0:
            return new Lake;
            break;
        case 1:
            return new Forest;
            break;
        default:
            return new Forest;
            break;
    }
}

void Print(Land **map, Player &player) {
    std::ostringstream thisMap;
            
            //Add Land Symbols to Map
            for(size_t i = 0; i < MAP_SIZE_Y; i++) {
                for(size_t k = 0; k < MAP_SIZE_X; k++) {
                    //Check if current coord is player
                    if((player.GetX() == k) && (player.GetY() == i)) {
                        thisMap << player.GetSymbol();
                    }
                    //If not, output normal map space
                    else {
                        thisMap << map[k][i].GetSymbol();
                    }
                }
                thisMap << std::endl;
            }
            
            //Output Final Map
            std::cout << thisMap.str() << std::endl;
}

/********

std::string Lake::GetShortDesc() const {
    return "Lake";
}

std::string Lake::GetLongDesc() const {
    return "You arrive at a large lake.";
}

std::string Lake::Visit(Player &player) {
    
    
    
}

/************************************************************/

std::string Forest::GetShortDesc() const {
    return "Forest";
}

std::string Forest::GetLongDesc() const {
    return "You arrive at a thick brush of trees.";
}
