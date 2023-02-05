// collectible.cpp
#include "collectible.h"
using namespace std;

Collectible::Collectible() : GameObject("Collectible", 100)
{
    name = "";
    strength = 0;
}

Collectible::Collectible(string label, int maxInstances, string n, int s) 
    : GameObject(label, maxInstances)
{
    name = n;
    strength = s;
}

void Collectible::setName(string n)
{
    name = n;
}

void Collectible::setStrength(int s)
{
    strength = s;
}