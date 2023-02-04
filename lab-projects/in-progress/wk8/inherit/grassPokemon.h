#ifndef GRASSPOKEMON_H
#define GRASSPOKEMON_H

#include "pokemon.h"

class GrassPokemon : public Pokemon {
    public:
        GrassPokemon(int, string, int, int, string, int);
        int getLeafStrength() const { return leafStrength; };
        void print() const;
    
    private:
        int leafStrength;
};

#endif