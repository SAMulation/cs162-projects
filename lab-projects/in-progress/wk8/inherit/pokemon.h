#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

using namespace std;

class Pokemon {
    public:
        Pokemon(int, string, int, int);
        Pokemon(int, string, int, int, string);
        int getId() const { return id; };
        string getName() const { return name; };
        int getLevel() const { return level; };
        int getExperience() const { return xp; };
        virtual void print() const;

    private:
        int id;
        string name;
        string type;
        int level;
        int xp;
};

#endif