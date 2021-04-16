#ifndef LAND_H
#define LAND_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "Character.h"

Land* BuildMap(size_t MAP_SIZE_X = 20, size_t MAP_SIZE_Y = 20);

enum LandTypes {LAKE, FOREST, DESERT, MAX_LAND_TYPES};

class Land {    
    public:
        //Descriptions
        virtual std::string GetShortDesc() const = 0;
        virtual std::string GetLongDesc() const = 0;
        virtual char GetSymbol() const = 0;
        
        virtual std::string Visit(Player &player) = 0;
        
        //Output Map Visual
        void Print(Land **map, Player &player);
};

class Lake : public Land {
    public:
        //Descriptions
        std::string GetShortDesc() const;
        std::string GetLongDesc() const;
        char GetSymbol() const {return symbol;}
        
        std::string Visit(Player &player);
        
    private:
        char symbol = 'L';
};

class Forest : public Land {
    public:
        //Descriptions
        std::string GetShortDesc() const;
        std::string GetLongDesc() const;
        char GetSymbol() const {return symbol;}
        
        std::string Visit(Player &player);
        
    private:
        char symbol = 'F';
};

class Desert : public Land {
    public:
        //Descriptions
        std::string GetShortDesc() const;
        std::string GetLongDesc() const;
        char GetSymbol() const {return symbol;}
        
        std::string Visit(Player &player);
        
    private:
        char symbol = 'D';
};

#endif
