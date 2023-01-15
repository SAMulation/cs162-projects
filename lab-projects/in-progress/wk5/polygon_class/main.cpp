/*************************
 * Name: Polygon class
 * Author: Sam Sarsten
 * Date: 01-14-2022
 * Purpose: Implementing Polygon class using C++
 * IMPORTANT: YOU MUST USE THIS COMMAND TO RUN IN VS CODE
 * g++ main.cpp polygon.cpp -o main && "PATH_TO_MAIN"main
 * Replit Link: https://replit.com/join/bfijbcqijf-samuelsarsten
**************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include "polygon.h"
using namespace std;

int main() {
    // Create a polygon using the default constructor
    Polygon poly1;

    // Test accessor and mutator functions
    cout << left;
    cout << "Polygon 1" << endl << "---------" << endl;
    cout << setw(17) << "Number of sides: " << poly1.get_n() << endl;
    cout << setw(17) << "Side length: " << poly1.get_side() << endl;
    cout << setw(17) << "X-coordinate: " << poly1.get_x() << endl;
    cout << setw(17) << "Y-coordinate: " << poly1.get_y() << endl;
    cout << setw(17) << "Perimeter: " << poly1.get_perimeter() << endl;
    cout << setw(17) << "Area: " << poly1.get_area() << endl << endl;

    poly1.set_n(5);
    poly1.set_side(2);
    poly1.set_x(1);
    poly1.set_y(1);

    // Test accessor and mutator functions
    cout << "Polygon 1 (After edits)" << endl << "-----------------------" << endl;
    cout << setw(17) << "Number of sides: " << poly1.get_n() << endl;
    cout << setw(17) << "Side length: " << poly1.get_side() << endl;
    cout << setw(17) << "X-coordinate: " << poly1.get_x() << endl;
    cout << setw(17) << "Y-coordinate: " << poly1.get_y() << endl;
    cout << setw(17) << "Perimeter: " << poly1.get_perimeter() << endl;
    cout << setw(17) << "Area: " << poly1.get_area() << endl << endl;

    // Create a polygon using the overloaded constructor
    Polygon poly2(6, 3, 2, 2);

    // Test accessor and mutator functions
    cout << "Polygon 2" << endl << "---------" << endl;
    cout << setw(17) << "Number of sides: " << poly2.get_n() << endl;
    cout << setw(17) << "Side length: " << poly2.get_side() << endl;
    cout << setw(17) << "X-coordinate: " << poly2.get_x() << endl;
    cout << setw(17) << "Y-coordinate: " << poly2.get_y() << endl;
    cout << setw(17) << "Perimeter: " << poly2.get_perimeter() << endl;
    cout << setw(17) << "Area: " << poly2.get_area() << endl;

    return 0;
}