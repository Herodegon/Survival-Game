#include "Character.h"

//Player's Options Per Turn
enum PlayerChoice {MOVE, LOOK, USE, HELP};

//Player's Options for Movement
enum Choice_Move {NORTH, SOUTH, EAST, WEST};

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
    std::string userInput;
            
    std::cout << "What will you do?\n";
    getline(std::cin, userInput);
    
    std::string str;
    str = 
            
    //TODO: Rethink Player Options; REMOVE
            
    //End of Turn
    hunger--; //Lose 1 Hunger
    thirst--; //Lose 1 Thirst
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
