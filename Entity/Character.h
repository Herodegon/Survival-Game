#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

//Player's Options Per Turn
enum PlayerChoice {MOVE, LOOK, USE, HELP};

//Player's Options for Movement
enum Choice_Move {NORTH, SOUTH, EAST, WEST};

/*********************************************************/

class Character : public Entity {
    public:
        virtual void Turn() = 0;
    
        bool IsAlive() const {return health;}
    
    protected:
        unsigned int health;
};

/*********************************************************/

class Player : public Character {
    public:
        Player(unsigned int health = 3, unsigned int hunger = 5, unsigned int thirst = 5) {
            this->health = health;
            this->hunger = hunger;
            this->thirst = thirst;
        }
        
        //Give Options and Get Player Input
        void Turn() {
            std::string userChoice;
            
            std::cout << "What will you do?\n";
            
            std::cin >> userChoice;
            
            //TODO: Rethink Player Options; REMOVE
            
            //End of Turn
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
        
        unsigned int playerCoord[2] = {0, 0};
};

#endif
