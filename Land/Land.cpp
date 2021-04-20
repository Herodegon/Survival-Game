#include "Land.h"

enum LandTypes {LAKE, FOREST, DESERT, PLAINS, CAVE, MAX_LAND_TYPES};

std::unique_ptr<Land> GetRandomLand() {
    LandTypes selection = (LandTypes)(rand() % MAX_LAND_TYPES);
    
    //!TEST selection; REMOVE
    std::cout << "Selection: " << selection << std::endl;
    
    switch(selection) {
        case LAKE:
            return std::make_unique<Lake>();
        case FOREST:
            return std::make_unique<Forest>();
        case DESERT:
            return std::make_unique<Desert>();
        case PLAINS:
            return std::make_unique<Plains>();
        case CAVE:
            return std::make_unique<Cave>();
        default:
            return std::make_unique<Forest>();
    }
}

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
        case 0: //The Good Sip
            std::cout << "The lake is freshwater. You take a sip and "
                      << "restore your thirst.\n";
            player.SetThirst(player.GetMaxThirst());
            break;
        case 1: //Berry Nice?
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
        case 2: //Dust Bowl
            std::cout << "The lake is dirty, and the dry air has left the "
                      << "the area devoid of life.\n";
            break;
        case 3: //Bear-ing Fruit
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
                                player.SetHealth(player.GetHealth()-2);
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
            } while(userInput == '!');
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
    int chance = rand() % 3;
    
    switch(chance) {
        case 0: //Nut A Chance
            std::cout << "You find a tree with nuts aplenty. Do you choose "
                      << "to \'T\'ake some, or \'W\'alk away?\n";
            char userInput;
            
            do {
                std::cin >> userInput;
                switch(userInput) {
                    case 'T':
                        std::cout << "You go for the nuts on the tree. ";
                        
                        chance = rand() % 2;
                        switch(chance) {
                            case 0:
                                std::cout << "A horde of squirrels catch wind of "
                                          << "your intentions, and make their "
                                          << "assault on your face. You walk "
                                          << "away empty handed as you pry the "
                                          << "squirrels from your scalp.\n";
                                player.SetHealth(player.GetHealth()-1);
                                break;
                            case 1:
                                std::cout << "Acorns fill the brims of your pockets, "
                                          << "leaving you deeply satisfied.\n";
                                player.SetHunger(player.GetMaxHunger());
                                break;
                        }
                        break;
                    case 'W':
                        std::cout << "You decide whatever risk you take going "
                                  << "up into that tree isn't worth it. Instead, "
                                  << "you try your luck elsewhere.\n";
                        break;
                    default:
                        std::cout << "Please enter \'T\' or \'W\'.\n";
                        userInput = '!'; //Input Error Flag
                        break;
                }
            } while(userInput == '!');
            break;
        case 1: //Bee-hind You!
            std::cout << "You run into a vicious horde of bees. Regret isn't "
                      << "the only swelling you have to deal with.\n";
            player.SetHealth(player.GetHealth()-1);
            break;
        case 2: //I Spy A River
            std::cout << "You spot a beautiful, flowing river. A sip or two "
                      << "and you're ready to head out again.\n";
            player.SetThirst(player.GetThirst()+1);
            break;
    }
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
    int chance = rand() % 2;
    
    switch(chance) {
        case 0: //Scorpion Sting
            break;
        case 1: //Miracle Mirage
            std::cout << "The heat has you pinned down. You think all hope "
                      << "is lost when you see a beautiful oasis far off into "
                      << "the distance. You contemplate \'H\'eading towards it, "
                      << "or \'T\'aking your chances in the heat.\n";
            char userInput;
            
            do {
                std::cin >> userInput;
                switch(userInput) {
                    case 'H':
                        std::cout << "You desperately hobble towards the oasis. ";
                        
                        chance = rand() % 2;
                        switch(chance) {
                            case 0:
                                chance = (rand() % 50) + 1;
                                
                                if(chance <= 45) {
                                    std::cout << "The oasis was nothing more than a "
                                              << "mirage. You've wasted a lot of energy "
                                              << "to get here, and for nothing.\n";
                                    player.SetHealth(player.GetHealth()-2);
                                    player.SetThirst(player.GetThirst()-2);
                                }
                                else {
                                    std::cout << "You fail to notice a pool of quicksand "
                                              << "before stepping right into it. You meet "
                                              << "your end as you slowly sink beneath the Earth.\n";
                                    player.SetHealth(0);
                                }
                                break;
                            case 1:
                                std::cout << "The oasis and bigger and more bountiful "
                                          << "than you could have imagined. You stay "
                                          << "for a while and rejuvinate.\n";
                                player.SetHealth(player.GetHealth()+2);
                                player.SetHunger(player.GetHunger()+2);
                                player.SetThirst(player.GetThirst()+2);
                                break;
                        }
                        break;
                    case 'T':
                        std::cout << "You choose to ignore the oasis, feeling it's "
                                  << "likely a figment of your delusional state. You "
                                  << "continue to travel as the heat wracks your health.\n";
                        player.SetHealth(player.GetHealth()-1);
                        player.SetThirst(player.GetThirst()-1);
                        break;
                    default:
                        std::cout << "Please enter \'T\' or \'W\'.\n";
                        userInput = '!'; //Input Error Flag
                        break;
                }
            } while(userInput == '!');
            break;
    }
}

/************************************************************/

std::string Plains::GetShortDesc() const {
    return "Desert";
}

std::string Plains::GetLongDesc() const {
    return "You arrive at a vast desert. ";
}

//!TODO: FINISH VISIT FUNCTION
void Plains::Visit(Player &player) {
    
}

/************************************************************/

std::string Cave::GetShortDesc() const {
    return "Desert";
}

std::string Cave::GetLongDesc() const {
    return "You arrive at a vast desert. ";
}

//!TODO: FINISH VISIT FUNCTION
void Cave::Visit(Player &player) {
    
}
