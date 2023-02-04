#ifndef FIREPOKEMON_H
#define FIREPOKEMON_H
#include "pokemon.h"

class FirePokemon : public Pokemon {
    public:
        FirePokemon(int, string, int, int, string, int);
        int getFlamePower() const { return flamePower; };
        void print() const;

    private:
        int flamePower;
};

#endif