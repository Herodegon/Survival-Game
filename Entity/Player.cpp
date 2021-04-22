#include "Character.h"

void Character::SetHealth(int health) {
    
    this->health = health;
    
    if(this->health < 0) {
        this->health = 0;
    }
    
    if(this->health > static_cast<int>(maxHealth)) {
        this->health = maxHealth;
    }
}

//Returns True if Player Still Has Health Left
bool Character::IsAlive() const {
    
    switch(health > 0) {
        case true:
            return true;
        case false:
            return false;
    }
}

/*********************************************************/

Player::Player() {
            
            this->health = DEFAULT_HEALTH;
            maxHealth = health;
            
            this->hunger = DEFAULT_HUNGER;
            maxHunger = hunger; 
            
            this->thirst = DEFAULT_THIRST;
            maxThirst = thirst;
}

Player::Player(int health, 
               int hunger, 
               int thirst) {
                   
    this->health = health;
    maxHealth = health;
    
    this->hunger = hunger;
    maxHunger = hunger;
            
    this->thirst = thirst;
    maxThirst = thirst;
}

void Player::Turn() {
    playerChoice = NOT_SPECIFIED;
    subChoice = -1;
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
                            subChoice = NORTH;
                            break;
                        case 'S':
                            subChoice = SOUTH;
                            break;
                        case 'E':
                            subChoice = EAST;
                            break;
                        case 'W':
                            subChoice = WEST;
                            break;
                        default:
                            std::cout << "Please choose one of the options.\n";
                            break;
                    }
                } while(subChoice == -1);
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

void Player::SetHunger(int hunger) {
    
    this->hunger = hunger;
    
    if(this->hunger < 0) {
        this->hunger = 0;
    }
    
    if(this->hunger > static_cast<int>(maxHunger)) {
        this->hunger = maxHunger;
    }
}

void Player::SetThirst(int thirst) {
    
    this->thirst = thirst;
    
    if(this->thirst < 0) {
        this->thirst = 0;
    }
    
    if(this->thirst > static_cast<int>(maxThirst)) {
        this->thirst = maxThirst;
    }
}

//Returns True if Player is Starving
bool Player::IsHungry() const {
    
    switch(hunger == 0) {
        case true:
            return true;
        case false:
            return false;
    }
}

//Returns True if Player is Thirsty
bool Player::IsThirsty() const {
    
    switch(thirst == 0) {
        case true:
            return true;
        case false:
            return false;
    }
}

//Either Upgrades or Downgrades One of Player's Max Stats
void Player::MaxStatChange(StatChanges changeType, Stats stat) {
    
    switch(changeType) {
        case UPGRADE: //Stat Upgrade
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
            
        case DOWNGRADE: //Stat Downgrade
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

//Displays Player Stats 
void Player::PrintStats() {
    std::cout << "Health: " << health
              << "Hunger: " << hunger
              << "Thirst: " << thirst;
}
