#include "waterPokemon.h"

WaterPokemon::WaterPokemon(int i, string n, int l, int x, string t, int p)
  : Pokemon(i, n, l, x, t), waterPressure(p) {}

void WaterPokemon::print() const {
  Pokemon::print();
  cout << "Water Pressure: " << waterPressure << endl;
  return;
}