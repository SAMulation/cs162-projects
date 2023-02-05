#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameObject.h"
using namespace std;

class Character : public GameObject {
    public:
        Character(string label = "", int maxInstances = 0, string name = "", 
                int health = 0, string superPower = "");

        void setName(string n) { name = n; return; }
        void setHealth(int h) { health = h; return; }
        void setSuperPower(string s) { superPower = s; return; }

        string getName() const { return name; }
        int getHealth() const { return health; }
        string getSuperPower() const { return superPower; }

    private:
        string name;
        int health;
        string superPower;
};

#endif