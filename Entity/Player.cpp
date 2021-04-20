#include "Character.h"

/*********************************************************/

Player::Player() {
            
            this->health = DEFAULT_HEALTH;
            maxHealth = health;
            
            this->hunger = DEFAULT_HUNGER;
            maxHunger = hunger; 
            
            this->thirst = DEFAULT_THIRST;
            maxThirst = thirst;
}

Player::Player(unsigned int health, 
               unsigned int hunger, 
               unsigned int thirst) {
                   
    this->health = health;
    maxHealth = health;
    
    this->hunger = hunger;
    maxHunger = hunger;
            
    this->thirst = thirst;
    maxThirst = thirst;
}

void Player::Turn() {
    playerChoice = NOT_SPECIFIED;
    choiceValue = -1;
    char userInput;
    
    do {    
        std::cout << "What do you want to do?\n"
                  << "Choose \'M\'ove or \'H\'elp for more info.\n";
        
        std::cin >> userInput;
        switch(userInput) {
            case 'M':
                playerChoice = MOVE;
                
                do {
                    std::cout << "Choose a direction: "
                              << "\'N\'orth, \'S\'outh, \'E\'ast, \'W\'est.\n";
                              
                    std::cin >> userInput;
                    switch(userInput) {
                        case 'N':
                            choiceValue = NORTH;
                            break;
                        case 'S':
                            choiceValue = SOUTH;
                            break;
                        case 'E':
                            choiceValue = EAST;
                            break;
                        case 'W':
                            choiceValue = WEST;
                            break;
                        default:
                            std::cout << "Please choose one of the options.\n";
                            break;
                    }
                } while(choiceValue == -1);
                break;
            case 'H':
                std::cout << "For now, you can only \'M\'ove. Sorry :(\n";
                break;
            default:
                std::cout << "Please choose an appropriate command.\n";
                break;
        }
    } while(playerChoice == NOT_SPECIFIED);
}

void Player::MaxStatChange(StatChanges changeType, Stats stat) {
    switch(changeType) {
        case UPGRADE:
            switch(stat) {
                case HEALTH:
                    maxHealth++;
                    break;
                    
                case HUNGER:
                    maxHunger++;
                    break;
                    
                case THIRST:
                    maxThirst++;
                    break;
            }
                
            break;
            
        case DOWNGRADE:
            switch(stat) {
                case HEALTH:
                    maxHealth--;
                    break;
                    
                case HUNGER:
                    maxHunger--;
                    break;
                    
                case THIRST:
                    maxThirst--;
                    break;
            }
                
            break;
    }
}

void Player::PrintStats() {
    std::cout << "Health: " << health
              << "Hunger: " << hunger
              << "Thirst: " << thirst;
}
