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

#include "Entity/Character.h"
#include "Land/Land.h"

enum MapSize {
    SMALL = 5,
    MEDIUM = 10,
    LARGE = 15,
    XLARGE = 20,
    
    UNDECLARED = -1
};

//Clears Terminal
void Clear() {for(int i = 0; i < 50; i++) {std::cout << std::endl;}}

//!TODO: FIX MAP GENERATOR; REMOVE
void BuildMap(Land *map, size_t MAP_SIZE_X = 20, size_t MAP_SIZE_Y = 20) {
    map = new Land[MAP_SIZE_X][MAP_SIZE_Y];
    playerSpawn_X = rand() % MAP_SIZE_X;
    playerSpawn_Y = rand() % MAP_SIZE_Y;
    
    for(size_t i = 0; i < MAP_SIZE_Y; i++) {
        for(size_t j = 0; j < MAP_SIZE_X; j++) {
            map[i][j] = new Lake;
            
            if((i == playerSpawn_Y) && (j == playerSpawn_X)) {
                player.SetCoord(i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    std::string userChoice;
    
    //Declare Map Size
    unsigned int MAP_SIZE_X = 20;
    unsigned int MAP_SIZE_Y = 20;
    
    MapSize sizeChoice = UNDECLARED;
    
    do {
        std::cout << "Choose a map size. "
                  << "(\'S\'mall, \'M\'edium, \'L\'arge, \'X\'-Large)\n";
        std::cin >> userChoice;
        
        switch(userChoice.at(0)) {
            case 'S':
                sizeChoice = SMALL;
                break;
            case 'M':
                sizeChoice = MEDIUM;
                break;
            case 'L':
                sizeChoice = LARGE;
                break;
            case 'X':
                sizeChoice = XLARGE;
                break;
            default:
                std::cout << "Please enter again.\n" << std::endl;
                break;
        }
    while(sizeChoice == UNDECLARED);
    
    MAP_SIZE_X = (rand() % 10) + sizeChoice;
    MAP_SIZE_Y = (rand() % 10) + sizeChoice;
    
    //Declare Map and Player
    Land *map[MAP_SIZE_X][MAP_SIZE_Y];
    Character *player = new Player;
    
    //Generate Game Map
    BuildMap(map);
    
    //---GAME START---
    std::cout << "You wake up in a "
              << map[player.GetX()][player.GetY()]->GetShortDesc()
              << " with no memory of how you got there.\n" << std::endl;
              
    
    return 0;
}
