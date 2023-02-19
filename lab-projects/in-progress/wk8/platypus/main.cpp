/*************************
 * Name: Platypus Class and Implementation
 * Author: Sam Sarsten
 * Date: 02-04-2023 (updated: 02-18-2023)
 * Purpose: Serious issues in Springfield implemented
 *          through this Platypus class
 * NOTE: If using VS Code, use the following 2 commands to run:
 *       g++ -o output_file main.cpp platypus.cpp
 *       ./output_file
 * HINT: Try with different inputs for MAX
**************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "platypus.h"
using namespace std;

const int MAX = 25;

int main() {
    vector<Platypus> platypi;
    srand(time(NULL));

    cout << "Welcome to the Springfield Nuclear Simulator!" << endl
         << "---------------------------------------------" << endl << endl;
    cout << "Let's create our first platypus..." << endl << endl;
    Platypus p1(0.5, 5, "Platy", 'f');
    cout << "Platypus 1: " << endl;
    p1.print();

    cout << endl << "Now let's hatch some more platypi..." << endl << endl;

    for (int i = 0; i < MAX; i++)
    {
        Platypus p;
        p.hatch();
        platypi.push_back(p);
    }

    cout << endl << "All platypi: " << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << "Platypus " << i + 1 << ": " << endl;
        platypi[i].print();
        cout << endl;
    }
    
    cout <<  endl <<"Now let's make our platypi grow and see what happens..." << endl << endl;
    for (int i = 0; i < 100; i++)
    {
        platypi[i].ageMe();
        for (int j = 0; j < 10; j++)
        {
            platypi[j].eat();
        }
    }

    cout << "All platypi after aging and eating..." << endl << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << "Platypus " << i + 1 << ": " << endl;
        platypi[i].print();
        cout << endl;
    }

    cout << endl << "Now let's make our platypi fight!!!" << endl << endl;
    for (int i = 0; i < MAX; i += 2)
    {
        platypi[i].fight(platypi[i + 1]);
    }

    int aliveCount = 0;
    int mutantCount = 0;

    cout << "All platypi after fighting..." << endl << endl;
    for (int i = 0; i < MAX; i++)
    {
        aliveCount += platypi[i].getAlive();
        mutantCount += platypi[i].getMutant();
        cout << "Platypus " << i + 1 << ": " << endl;
        platypi[i].print();
        cout << endl;
    }

    cout << "Total alive platypi: " << aliveCount << "/" << MAX << endl
         << "Total mutant platypi: " << mutantCount << "/" << MAX << endl;

    cout << endl << "That's all folks! Goodbye from Springfield!" << endl
         << "Hope you had an exxxxxxellent time!!!" << endl;
    return 0;
}