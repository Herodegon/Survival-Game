#ifndef LAND_H
#define LAND_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "../Entity/Character.h"

class Land {    
    public:
        //Descriptions
        virtual std::string GetShortDesc() const = 0;
        virtual std::string GetLongDesc() const = 0;
        virtual char GetSymbol() const = 0;
        
        virtual void Visit(Player &player) = 0;
};

class Lake : public Land {
    public:
        //Descriptions
        std::string GetShortDesc() const;
        std::string GetLongDesc() const;
        char GetSymbol() const {return symbol;}
        
        void Visit(Player &player);
        
    private:
        char symbol = 'L';
};

class Forest : public Land {
    public:
        //Descriptions
        std::string GetShortDesc() const;
        std::string GetLongDesc() const;
        char GetSymbol() const {return symbol;}
        
        void Visit(Player &player);
        
    private:
        char symbol = 'F';
};

class Desert : public Land {
    public:
        //Descriptions
        std::string GetShortDesc() const;
        std::string GetLongDesc() const;
        char GetSymbol() const {return symbol;}
        
        void Visit(Player &player);
        
    private:
        char symbol = 'D';
};

class Mountain : public Land {
    public:
        //Descriptions
        std::string GetShortDesc() const;
        std::string GetLongDesc() const;
        char GetSymbol() const {return symbol;}
        
        void Visit(Player &player);
        
    private:
        char symbol = 'M';
};

Land* GetRandomLand(void);

#endif
