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
              << " with no memory of how you got there.\n"
              << std::endl << "Press \'ENTER\' to continue...\n";
              
    std::cin.get();
    std::cin.ignore();
    
    do {
        //Clears Screen and Prints ASCII Map
        Clear();
        map.Print(player);
        
        //Prints Player Stats and Executes Players Turn Phase
        player.PrintStats();
        map.Turn(player);
        
        /*!TEST player stats; REMOVE
        std::cout << "Health: " << player.GetHealth() << std::endl
                  << "Hunger: " << player.GetHunger() << std::endl
                  << "Thirst: " << player.GetThirst() << std::endl
                  << std::endl;
        */
        
        //Executes Random Land Event
        map.At(player.GetX(), player.GetY())->Visit(player);
        
        //Confirms End of Turn
        std::cout << std::endl << "Press \'ENTER\' to continue...\n";
        
        std::cin.get();
        std::cin.ignore();
    } while(player.IsAlive());
    
    std::cout << "You succumb to your exhaustion.\n"
              << std::endl;
    
    return 0;
}
