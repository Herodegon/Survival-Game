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

void Turn() {
    
}

int main() {
    srand(time(NULL));
    
    //Declare Map and Player
    Player player;
    Map map(player); //NOTE: Map is generated upon definition
    
    //---GAME START---
    Clear();
    
    map.Print(player);
    
    std::cout << "You wake up in a "
              << map.At(player.GetX(), player.GetY())->GetShortDesc()
              << " with no memory of how you got there.\n" << std::endl;
              
    //!TEST Current Limits | End Of Program; REMOVE
    std::cout << std::endl
              << "Execution Successful!\n";
    return 0;
    
    /*
    do {  
        //Player Turn
        player.Turn();
    } while(player.IsAlive());
    
    return 0;
    */
}
