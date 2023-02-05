#include "character.h"
using namespace std;

Character::Character(string label, int maxInstances, string n, 
                     int h, string s) : GameObject(label, maxInstances) {
    name = n;
    health = h;
    superPower = s;
}