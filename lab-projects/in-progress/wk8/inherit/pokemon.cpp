#include "pokemon.h"

Pokemon::Pokemon(int i, string n, int l, int x) : id(i), name(n), level(l), xp(x), type("None") {}

Pokemon::Pokemon(int i, string n, int l, int x, string t) : id(i), name(n), level(l), xp(x), type(t) {}

void Pokemon::print() const {
  cout << "ID: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Type: " << type << endl;
  cout << "Level: " << level << endl;
  cout << "XP: " << xp << endl;
}