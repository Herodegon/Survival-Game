#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

class Entity {
    public:
        //Get Entity Name
        virtual std::string GetName() const = 0;
        //Get Entity Description
        virtual std::string GetDesc() const = 0;
        //Get Entity Symbol
        virtual char GetSymbol() const = 0;
};

#endif
