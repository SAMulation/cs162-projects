#include "grassPokemon.h"

GrassPokemon::GrassPokemon(int i, string n, int l, int x, int p)
  : Pokemon(i, n, l, x, "Grass"), leafStrength(p) {}

void GrassPokemon::print() const {
  Pokemon::print();
  cout << "Leaf Strength: " << leafStrength << endl;
  return;
}