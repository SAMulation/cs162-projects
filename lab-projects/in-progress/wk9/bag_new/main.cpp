/*************************
 * Name: Bag Class from Class - Updated
 * Author: Sam Sarsten
 * Date: 02-04-2023
 * Purpose: Bag class from Making CS Easy channel
 *          with the added functions from assn
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
    b1.insert(10);
    b1.insert(2);
    
    cout << "Elements in the Bag: ";
    for (int i = 0; i < b1.size(); i++)
        cout << b1.getValue(i) << " ";
    cout << endl;

    cout << "Sum of elements in the Bag: " << b1.showSum() << endl;
    cout << "Largest value in the Bag: " << b1.largest() << endl;

    Bag b2;
    b2.insert(8);
    b2.insert(7);
    b2.insert(10);

    if (b1 == b2)
        cout << "Bags are equal" << endl;
    else
        cout << "Bags are not equal" << endl;

    b2.insert(2);

    if (b1 == b2)
        cout << "Bags are equal" << endl;
    else
        cout << "Bags are not equal" << endl;

    b1.removeAll(7);

    cout << "Elements in the Bag after removing all copies of 7: ";
    for (int i = 0; i < b1.size(); i++)
        cout << b1.getValue(i) << " ";
    cout << endl;

    return 0;
}