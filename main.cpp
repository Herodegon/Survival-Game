/*********************************************************
 * Game Goal: Survive as long as possible
 * 
 * 3 Properties:
 * - Health
 * - Hunger
 * - Thirst
 * 
 * Game World:
 * -------------------------
 * |                       |
 * |                       |
 * |                       |
 * |                       |
 * |          *            |
 * |                       |
 * |                       |
 * |                       |
 * -------------------------
 * 
 * Player can move in four directions
 * 
 * Each space is Land
 * Land can be:
 * - Lake
 * - Field
 * - Forest
 ********************************************************/

#include <iostream>

#include "Character.h"
#include "Land.h"

void Clear() {for(int i = 0; i < 50; i++) {std::cout << std::endl;}}

int main() {
    const unsigned int MAP_SIZE = 20;
    Player player(player::DEFAULT_HEALTH,
                  player::DEFAULT_HUNGER,
                  player::DEFAULT_THIRST);
    
    //Build Map
    Land* map[map->MAP_SIZE_X][map->MAP_SIZE_Y];
    for(size_t i = 0; i < MAP_SIZE; i++) {
        for(size_t j = 0; j < MAP_SIZE; j++) {
            map[i][j] = new Lake;
            
            if((i == MAP_SIZE/2) && (j == MAP_SIZE/2)) {
                player.SetPlayerCoord(i, j);
            }
        }
    }
    
    std::cout << "You wake up in a "
              << map[player.GetX()][player.GetY()]->GetShortDesc()
              << " with no memory of how you got there.\n" << std::endl;
    
    while(player.IsAlive()) {
        std::cout << "What would you like to do?";
        //!TODO: Make Turn Independent of main.cpp 
        //Player.Turn();
        Clear();
    }
    
    return 0;
}
