#include "Land.h"

enum LandTypes {LAKE, FOREST, DESERT, MAX_LAND_TYPES};

std::unique_ptr<Land> GetRandomLand() {
    srand(time(NULL));
    LandTypes selection = (LandTypes)(rand() % MAX_LAND_TYPES);
    
    switch(selection) {
        case LAKE:
            return std::make_unique<Lake>();
        case FOREST:
            return std::make_unique<Forest>();
        case DESERT:
            return std::make_unique<Desert>();
        default:
            return std::make_unique<Forest>();
    }
}

/*!TODO: FIX PRINT FUNCTION
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
*/

/************************************************************/

std::string Lake::GetShortDesc() const {
    return "Lake";
}

std::string Lake::GetLongDesc() const {
    return "You arrive at a large lake. ";
}

void Lake::Visit(Player &player) {
    int chance = rand() % 4;
    
    switch(chance) {
        case 0:
            std::cout << "The lake is freshwater. You take a sip and "
                      << "restore your thirst.\n";
            player.SetThirst(player.GetMaxThirst());
            break;
        case 1:
            std::cout << "There's greenery surrounding the lake.\n";
            
            chance = rand() % 2;
            switch(chance) {
                case 0:
                    std::cout << "They're covered in fruits and berries. "
                              << "You grab what you can.\n";
                    player.SetHunger(player.GetMaxHunger());
                    break;
                case 1:
                    std::cout << "You spot a few bushes with berries on "
                              << "them. You take what little they have.\n";
                    player.SetHunger(player.GetHunger()+1);
                    break;
            }
            break;
        case 2:
            std::cout << "The lake is dirty, and the dry air has left the "
                      << "the area devoid of life.\n";
            break;
        case 3:
            std::cout << "A bear is stalking the outskirts of the lake. "
                      << "You think it might be possible to sneak by.\n"
                      << "Do you \'S\'neak or \'R\'un?\n";
            char userInput;
            
            do {
                switch(userInput) {
                    case 'S':
                        std::cout << "You try to sneak past the bear. ";
                        
                        chance = rand() % 2;
                        switch(chance) {
                            case 0:
                                std::cout << "It works, and you manage to get "
                                          << "a good fill of water before making "
                                          << "your way to safety.\n";
                                player.SetThirst(player.GetMaxThirst());
                                break;
                            case 1:
                                std::cout << "You're spotted by the bear and "
                                          << "attacked. You take a lot of damage "
                                          << "trying to get away.\n";
                                player.SetHealth(player.GetHealth()-1);
                                break;
                        }
                        break;
                    case 'R':
                        std::cout << "You run as far away from the lake as you "
                                  << "can before you decide it's safe enough "
                                  << "to stop.\n";
                        break;
                    default:
                        std::cout << "Please enter \'S\' or \'R\'.\n";
                        userInput = '!'; //Input Error Flag
                        break;
                }
            } while(userInput != '!');
    }
}

/************************************************************/

std::string Forest::GetShortDesc() const {
    return "Forest";
}

std::string Forest::GetLongDesc() const {
    return "You arrive at a thick brush of trees. ";
}

//!TODO: FINISH VISIT FUNCTION
void Forest::Visit(Player &player) {
    
}

/************************************************************/

std::string Desert::GetShortDesc() const {
    return "Desert";
}

std::string Desert::GetLongDesc() const {
    return "You arrive at a vast desert. ";
}

//!TODO: FINISH VISIT FUNCTION
void Desert::Visit(Player &player) {
    
}
