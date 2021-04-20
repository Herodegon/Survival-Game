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

#include "Map/Map.h"

//Clears Terminal
void Clear() {for(int i = 0; i < 50; i++) {std::cout << std::endl;}}

/*!TODO: FIX MAP GENERATOR; REMOVE
void BuildMap(Player player, size_t MAP_SIZE_X = 20, size_t MAP_SIZE_Y = 20) {
    Land* map[MAP_SIZE_X][MAP_SIZE_Y];
    unsigned int playerSpawn_X = rand() % MAP_SIZE_X;
    unsigned int playerSpawn_Y = rand() % MAP_SIZE_Y;
    
    for(size_t i = 0; i < MAP_SIZE_Y; i++) {
        for(size_t j = 0; j < MAP_SIZE_X; j++) {
            map[i][j] = new Lake;
            
            if((i == playerSpawn_Y) && (j == playerSpawn_X)) {
                player.SetCoord(i, j);
            }
        }
    }
}
*/

//!TODO: Change AllCapsArgs to Lower Case
//!TODO: Create Class for Maps

int main() {
    /*!Moved To Seperate Class
    srand(time(NULL));
    std::string userChoice;
    
    //Declare Map Size
    unsigned int size_X = 20;
    unsigned int size_Y = 20;
    
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
    } while(sizeChoice == UNDECLARED);
    
    MAP_SIZE_X = (rand() % 10) + sizeChoice;
    MAP_SIZE_Y = (rand() % 10) + sizeChoice;
    */
    
    //Declare Map and Player
    Player player;
    Map map(player);
    
    //Generate Game Map
    
    /*!Moved to Seperate Class
    //Create random coordinate for player spawn
    unsigned int playerSpawn_X = rand() % MAP_SIZE_X;
    unsigned int playerSpawn_Y = rand() % MAP_SIZE_Y;
    player.SetCoord(playerSpawn_X, playerSpawn_Y); //!Might be better than below
    
    for(size_t i = 0; i < MAP_SIZE_Y; i++) {
        for(size_t k = 0; k < MAP_SIZE_X; k++) {
            
            //!TEST iteration; REMOVE
            std::cout << "BuildMap [" << k << "][" << i << "]" << std::endl;
            
            map[k][i] = new Lake;
            
            //!TEST failsafe; REMOVE
            if(k > 100) {
                break;
            }
        }
    }
    */
    
    /*
    std::cout << "Execution Success!\n";
    return 0;
    */
    
    //---GAME START---
    Clear();
    
    map.Print(player);
    
    std::cout << "You wake up in a "
              << map.At(player.GetX(), player.GetY())->GetShortDesc()
              << " with no memory of how you got there.\n" << std::endl;
              
    //Current Limits | End Of Program
    std::cout << std::endl
              << "Execution Successful!\n";
    return 0;
    
    /*
    do {
        //!Moved To Seperate Class
        //Print Map
        std::ostringstream thisMap;
        
        //Add Land Symbols to Map
        for(size_t i = 0; i < MAP_SIZE_Y; i++) {
            for(size_t k = 0; k < MAP_SIZE_X; k++) {
                //Check if current coord is player
                
                //!TEST LOOP; REMOVE
                std::cout << "Iteration [" << k << "][" << i << "]" << std::endl;
                
                if((player.GetX() == k) && (player.GetY() == i)) {
                    thisMap << player.GetSymbol();
                }
                //If not, output normal map space
                else {
                    thisMap << map[k][i]->GetSymbol();
                }
            }
            thisMap << std::endl;
        }
        
        //Output Final Map
        std::cout << thisMap.str() << std::endl;
        
        //Player Turn
        player.Turn();
    } while(player.IsAlive());
    
    return 0;
    */
}
