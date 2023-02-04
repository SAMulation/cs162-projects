#include "firePokemon.h"

FirePokemon::FirePokemon(int i, string n, int l, int x, string t, int p)
  : Pokemon(i, n, l, x, t), flamePower(p) {}

void FirePokemon::print() const {
    Pokemon::print();
    cout << "Flame Power: " << flamePower << endl;
    return;
}