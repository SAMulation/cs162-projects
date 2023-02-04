#ifndef WATERPOKEMON_H
#define WATERPOKEMON_H
#include "pokemon.h"
#include <string>
#include <iostream>
using namespace std;

class WaterPokemon : public Pokemon {
    public:
        WaterPokemon(int, string, int, int, string, int);
        int getWaterPressure() { return waterPressure; }
        void print() const;

    private:
        int waterPressure;
};

#endif