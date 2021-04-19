#ifndef CHARACTER_H
#define CHARACTER_H

#include <algorithm>

#include "Entity.h"

enum CharacterTypes {PLAYER, ANIMAL, NPC, MAX_NUM_CHARS};

class Character : public Entity {
    public:
        //Character Turn
        virtual void Turn() = 0;
    
        //Adjust Character Health
        void SetHealth(unsigned int health) {this->health = health;}
        
        //Character Health Check
        bool IsAlive() const {return health;}
        
        //Set Full Coordinate
        void SetCoord(unsigned int x, unsigned int y = 0) {
            SetX(x);
            SetY(y);
        }
        //Set Position on Axis
        void SetX(unsigned int x) {coord[0] = x;}
        void SetY(unsigned int y) {coord[1] = y;}
        
        //Get Position on Axis
        unsigned int GetX() const {return coord[0];}
        unsigned int GetY() const {return coord[1];}
    
    protected:
        unsigned int health;
        
        unsigned int coord[2] = {0,0};
};

/*********************************************************/

enum Stats {HEALTH, HUNGER, THIRST};

class Player : public Character {
    public:
        Player(unsigned int health = DEFAULT_HEALTH, 
               unsigned int hunger = DEFAULT_HUNGER, 
               unsigned int thirst = DEFAULT_THIRST) {
            
            this->health = health;
            maxHealth = health;
            
            this->hunger = hunger;
            maxHunger = hunger;
            
            this->thirst = thirst;
            maxThirst = thirst;
        }
        
        //Give Options and Get Player Input
        void Turn();
        
        //Upgrade Player Stat
        void UpgradeStat(Stats playerStat);
        
        //Output Player Stats
        void PrintStats();
        
        static unsigned int const DEFAULT_HEALTH = 3;
        static unsigned int const DEFAULT_HUNGER = 10;
        static unsigned int const DEFAULT_THIRST = 5;
        
        
        
    private:
        unsigned int hunger;
        unsigned int thirst;
        
        unsigned int maxHealth;
        unsigned int maxHunger;
        unsigned int maxThirst;
        
        unsigned int playerCoord[2] = {0, 0};
};

#endif
