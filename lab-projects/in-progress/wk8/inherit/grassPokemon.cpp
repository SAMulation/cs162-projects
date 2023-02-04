#include "grassPokemon.h"

GrassPokemon::GrassPokemon(int i, string n, int l, int x, string t, int p)
  : Pokemon(i, n, l, x, t), leafStrength(p) {}

void GrassPokemon::print() const {
  Pokemon::print();
  cout << "Leaf Strength: " << leafStrength << endl;
  return;
}