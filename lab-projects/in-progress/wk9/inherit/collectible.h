// collectible.h
#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H
#include "gameObject.h"
using namespace std;

class Collectible : public GameObject
{
    public:
        Collectible();
        Collectible(string, int, string, int);

        string getName() const { return name; };
        int getStrength() const { return strength; };

        void setName(string);
        void setStrength(int);

    private:
        string name;
        int strength;
};

#endif
