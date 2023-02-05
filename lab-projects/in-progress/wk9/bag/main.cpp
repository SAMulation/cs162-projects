/*************************
 * Name: Bag Class from Class
 * Author: Sam Sarsten
 * Date: 02-04-2023
 * Purpose: Bag class from Making CS Easy channel
 * NOTE: If using VS Code, use the following 2 commands to run:
 *       g++ -o output_file main.cpp bag.cpp
 *       ./output_file
**************************/

#include <iostream>
#include "bag.h"
using namespace std;

int main() {
    Bag b1;
    b1.insert(8);
    b1.insert(7);
    
    for (int i = 0; i < b1.size(); i++)
        cout << b1.getValue(i) << endl;

    return 0;
}