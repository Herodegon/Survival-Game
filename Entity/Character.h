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
        
        unsigned int GetHealth() {return health;}
        
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
enum StatChanges {UPGRADE, DOWNGRADE};

class Player : public Character {
    public:
        Player();
        
        Player(unsigned int health, 
               unsigned int hunger, 
               unsigned int thirst);
        
        //Give Options and Get Player Input
        void Turn();
        
        //Use Player Stats
        void SetHunger(unsigned int hunger) {this->hunger = hunger;}
        void SetThirst(unsigned int thirst) {this->thirst = thirst;}
        
        unsigned int GetHunger() {return hunger;}
        unsigned int GetThirst() {return thirst;}
        
        unsigned int GetMaxHealth() {return maxHealth;}
        unsigned int GetMaxHunger() {return maxHunger;}
        unsigned int GetMaxThirst() {return maxThirst;}
        
        //Player Info
        void SetName(std::string name) {this->name = name;}
        
        std::string GetName() const {return name;}
        std::string GetDesc() const {return desc;}
        char GetSymbol() const {return symbol;}
        
        //Upgrade Stats
        void MaxStatChange(StatChanges changeType, Stats stat);
        
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
        
        std::string name;
        std::string desc = "The Player";
        char symbol = '@';
};

#endif
