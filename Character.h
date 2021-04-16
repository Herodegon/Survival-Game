#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

enum CharChoice {NORTH, SOUTH, EAST, WEST};

class Character : public Entity {
    public:
        virtual bool Turn() = 0;
        
        bool IsAlive() const = {return health;}
    
    protected:
        unsigned int health;
};

class Player : public Character {
    public:
        Player(unsigned int health, unsigned int hunger, unsigned int thirst) {
            this->health = health;
            this->hunger = hunger;
            this->thirst = thirst;
        }
        
        //Give Options and Get Player Input
        bool Turn() {
            char playerStr;
            
            std::cout << "What will you do?\n"
                      << "Enter \'N\', \'S\', \'E\', or \'W\'.\n";
            
            std::cin >> playerStr;
            switch(playerStr) {
                case 'N':
                    playerChoice = NORTH;
                    break;
                    
                case 'S':
                    playerChoice = SOUTH;
                    break;
                    
                case 'E':
                    playerChoice = EAST;
                    break;
                    
                case 'W':
                    playerChoice = WEST;
                    break;
            }
            
            //End of Turn
            switch(playerChoice) {
                case NORTH:
            
            hunger--; //Lose 1 Hunger
            thirst--; //Lose 1 Thirst
        }
        
        //Output Player Stats
        void PrintStats() {
            std::cout << "Health: " << health
                      << "Hunger: " << hunger
                      << "Thirst: " << thirst;
        }
        
        static const unsigned int DEFAULT_HEALTH = 3;
        static const unsigned int DEFAULT_HUNGER = 10;
        static const unsigned int DEFAULT_THIRST = 5;
        
    private:
        unsigned int hunger;
        unsigned int thirst;
        
        CharChoice playerChoice;
        
        unsigned int playerCoord[2] = {0, 0};
};

#endif
