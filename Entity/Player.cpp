#include "Character.h"

//Player's Options Per Turn
enum PlayerChoice {MOVE, LOOK, USE, HELP};

//Player's Options for Movement
enum Choice_Move {NORTH, SOUTH, EAST, WEST};

/*********************************************************/

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

void Player::PrintStats() {
    std::cout << "Health: " << health
              << "Hunger: " << hunger
              << "Thirst: " << thirst;
}
