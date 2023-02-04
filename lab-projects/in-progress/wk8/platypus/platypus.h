#ifndef PLATYPUS_H
#define PLATYPUS_H
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Platypus {
    public:
        Platypus();
        Platypus(float, short, string, char);
        void print();
        void ageMe();
        void fight(Platypus&);
        void eat();
        void hatch();
        string getRandomName(char gender);

    private:
        float weight;
        short age;
        string name;
        char gender;
        bool alive;
        bool mutant;
};

#endif