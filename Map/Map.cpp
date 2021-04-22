#include "Map.h"

//All Map Sizes (for unsigned usage)
enum MapSize {
    SMALL = 5,
    MEDIUM = 10,
    LARGE = 15,
    XLARGE = 20,
    
    UNDECLARED = -1 //Signed Value for Flag Usage
};

void Map::ChooseMapSize() {
    srand(time(NULL));
    std::string userChoice;
    
    //Declare Default Map Size
    map_X = 20;
    map_Y = 20;
    
    MapSize sizeChoice = UNDECLARED;
    
    //Get User Input for Map Size
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
    
    //      (  ?    % 10) + 5|10|15|20
    map_X = (rand() % 10) + sizeChoice;
    map_Y = (rand() % 10) + sizeChoice;
}

void Map::BuildMap(Player &player) {
    
    //Create random coordinate for player spawn
    unsigned int playerSpawn_X = rand() % map_X;
    unsigned int playerSpawn_Y = rand() % map_Y;
    player.SetCoord(playerSpawn_X, playerSpawn_Y);
    
    //!TEST player spawn; REMOVE
    std::cout << "Player Spawn: (" << playerSpawn_X << ", "
              << playerSpawn_Y << ")" << std::endl;
    
    for(size_t i = 0; i < map_Y; i++) {
        for(size_t k = 0; k < map_X; k++) {
            
            //!TEST iteration; REMOVE
            std::cout << "BuildMap [" << k << "][" << i << "]" << std::endl;
            
            map[k][i] = GetRandomLand();
            
            //!TEST land; REMOVE
            std::cout << "Symbol: \'" << map[k][i]->GetSymbol() << "\'" << std::endl
                      << std::endl;
            
            //!TEST failsafe; REMOVE
            if(k > 100) {
                break;
            }
        }
    }
}

void Map::Turn(Player &player) {
    bool fail;
    
    do {
        fail = false;
        
        player.Turn();
        
        switch(player.GetChoice()) {
            case MOVE:
                Move(player, player.GetSubchoice());
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

void Map::Move(Character &_char, unsigned int dir) {
    
    Choices_Move move = static_cast<Choices_Move>(dir);
    switch(move) {
        case NORTH:
            //If player is not at the top of the map
            if(!(_char.GetY() == (map.size() - 1) )) {
                _char.SetY(_char.GetY() + 1);
            }
            //Else, set them at the bottom
            else {
                _char.SetY(0);
            }
            break;
        case SOUTH:
            //If player is not at the bottom of the map
            if(!(_char.GetY() == 0)) {
                _char.SetY(_char.GetY() - 1);
            }
            //Else, set them at the top
            else {
                _char.SetY(map.size() - 1);
            }
            break;
        case EAST:
            //If player is not at the far right of the map
            if(!(_char.GetX() == (map[_char.GetX()].size() - 1) )) {
                _char.SetX(_char.GetX() + 1);
            }
            //Else, set them at the far left
            else {
                _char.SetX(0);
            }
            break;
        case WEST:
            //If player is not at the far left of the map
            if(!(_char.GetX() == 0)) {
                _char.SetX(_char.GetX() - 1);
            }
            //Else, set them at the far right
            else {
                _char.SetX(map[_char.GetX()].size() - 1);
            }
            break;
    }
}

void Map::Print(Player &player) {
    std::ostringstream thisMap;
    
    //Add Land Symbols to Map
    for(size_t i = 0; i < map_Y; i++) {
        for(size_t k = 0; k < map_X; k++) {
            
            //Check if current coord is player
                
            //!TEST loop; REMOVE
            std::cout << "Iteration [" << k << "][" << i << "]" << std::endl
                      << "Symbol: \'" << map[k][i]->GetSymbol() << "\'" << std::endl
                      << std::endl;
            
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
}
