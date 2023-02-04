/*************************
 * Name: Pokemon Class with Derived Classes
 * Author: Sam Sarsten
 * Date: 02-03-2023
 * Purpose: Implementing a Pokemon class in C++
 *          with derived classes
 * NOTE: If using VS Code, use the following 2 commands to run:
 *       g++ -o output_file main.cpp Pokemon.cpp GrassPokemon.cpp FirePokemon.cpp WaterPokemon.cpp
 *       ./output_file
**************************/

#include <iostream>
#include "pokemon.h"
#include "grassPokemon.h"
#include "firePokemon.h"
#include "waterPokemon.h"

using namespace std;

int main() {
  Pokemon *p1 = new GrassPokemon(1, "Bulbasaur", 5, 50, "Grass", 30);
  Pokemon *p2 = new FirePokemon(2, "Charmander", 7, 60, "Fire", 50);
  Pokemon *p3 = new WaterPokemon(3, "Squirtle", 6, 55, "Water", 40);

  cout << "Pokemon 1: " << endl;
  p1->print();
  cout << endl;

  cout << "Pokemon 2: " << endl;
  p2->print();
  cout << endl;

  cout << "Pokemon 3: " << endl;
  p3->print();
  cout << endl;

  return 0;
}