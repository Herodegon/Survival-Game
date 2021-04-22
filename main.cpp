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
              << " with no memory of how you got there.\n" << std::endl;
              
    std::cin.get();
    std::cin.ignore();
    
    do {
        //Clears Screen and Prints ASCII Map
        Clear();
        map.Print(player);
        
        //Runs Main Turn
        map.Turn(player);
        
        //Executes Random Land Event
        map.At(player.GetX(), player.GetY())->Visit(player);
    } while(player.IsAlive());
    
    return 0;
}

/*!Moved to Class Function (Map.h); REMOVE
void Turn(Player &player, Map &map) {
    bool fail;
    
    do {
        fail = false;
        
        player.Turn();
        
        switch(player.GetChoice()) {
            case MOVE:
                map.Move(player, player.GetSubchoice());
                break;
            default:
                std::cout << "ERROR: Could Not Deduce Player Choice. "
                          << "Please Try Again.\n";
                fail = true;
                break;
        }
    } while(fail == true);
    
    //End of Turn
    if(player.GetHunger() != 0) {
        player.SetHunger(player.GetHunger()-1);
    }
    else {
        player.SetHealth(player.GetHealth()-1);
    }
    
    if(player.GetThirst() != 0) {
        player.SetThirst(player.GetThirst()-1);
    }
    else {
        player.SetHealth(player.GetHealth()-1);
    }
}
*/
