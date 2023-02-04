#ifndef WATERPOKEMON_H
#define WATERPOKEMON_H
#include "pokemon.h"

class WaterPokemon : public Pokemon {
    public:
        WaterPokemon(int, string, int, int, int);
        int getWaterPressure() { return waterPressure; }
        void print() const;

    private:
        int waterPressure;
};

#endif