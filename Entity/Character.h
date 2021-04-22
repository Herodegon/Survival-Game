#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

enum CharacterTypes {PLAYER, ANIMAL, NPC, MAX_NUM_CHARS};

class Character : public Entity {
    public:
        //Character Turn
        virtual void Turn() = 0;
    
        //Adjust Character Health
        void SetHealth(int health);
        
        int GetHealth() {return health;}
        
        unsigned int GetMaxHealth() const {return maxHealth;}
        
        //Character Health Check
        bool IsAlive() const;
        
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
        int health;
        
        unsigned int maxHealth;
        
        unsigned int coord[2] = {0,0};
};

/*********************************************************/

//Player Stats
enum Stats {HEALTH, HUNGER, THIRST};
enum StatChanges {UPGRADE, DOWNGRADE};

//Player Actions
enum Choices {MOVE, HELP, MAX_CHOICES, NOT_SPECIFIED = -1};

//Player's Options for Movement
enum Choices_Move {NORTH, SOUTH, EAST, WEST};

class Player : public Character {
    public:
        Player();
        
        Player(int health, int hunger, int thirst);
        
        //Give Options and Get Player Input
        void Turn();
        
        unsigned int GetChoice() const {return static_cast<unsigned int>(playerChoice);}
        unsigned int GetSubchoice() const {return subChoice;}
        
        //Use Player Stats
        void SetHunger(int hunger);
        void SetThirst(int thirst);
        
        int GetHunger() const {return hunger;}
        int GetThirst() const {return thirst;}
        
        unsigned int GetMaxHunger() const {return maxHunger;}
        unsigned int GetMaxThirst() const {return maxThirst;}
        
        //Player Stat Checks
        bool IsHungry() const;
        bool IsThirsty() const;
        
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
        int hunger;
        int thirst;
        
        unsigned int maxHunger;
        unsigned int maxThirst;
        
        unsigned int playerCoord[2] = {0, 0};
        Choices playerChoice = NOT_SPECIFIED;
        int subChoice = -1;
        
        //Player Info
        std::string name = "Player";
        std::string desc = "The Player";
        char symbol = '@';
};

#endif
