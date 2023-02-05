/*************************
 * Name: Platypus Class and Implementation
 * Author: Sam Sarsten
 * Date: 02-04-2023
 * Purpose: Serious issues in Springfield implemented
 *          through this Platypus class
 * NOTE: If using VS Code, use the following 2 commands to run:
 *       g++ -o output_file main.cpp playpus.cpp
 *       ./output_file
**************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "platypus.h"
using namespace std;

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

    for (int i = 0; i < 10; i++)
    {
        Platypus p;
        p.hatch();
        platypi.push_back(p);
    }

    cout << endl << "All platypi: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Platypus " << i + 1 << ": " << endl;
        platypi[i].print();
        cout << endl;
    }
    
    cout <<  endl <<"Now let's make our platypi grow and see what happens..." << endl << endl;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            platypi[j].ageMe();
            platypi[j].eat();
        }
    }

    cout << "All platypi after aging and eating..." << endl << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Platypus " << i + 1 << ": " << endl;
        platypi[i].print();
        cout << endl;
    }

    cout << endl << "Now let's make our platypi fight!!!" << endl << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
            platypi[i].fight(platypi[j]);
    }

    cout << "All platypi after fighting..." << endl << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Platypus " << i + 1 << ": " << endl;
        platypi[i].print();
        cout << endl;
    }

    cout << endl << "That's all folks! Goodbye from Springfield!" << endl
         << "Hope you had an exxxxxxellent time!!!" << endl;
    return 0;
}