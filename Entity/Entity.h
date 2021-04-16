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
        unsigned int coord[2] = {0,0};
};

#endif
