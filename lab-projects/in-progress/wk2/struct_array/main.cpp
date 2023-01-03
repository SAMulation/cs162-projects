/*************************
 * Name: 2-D Coordinate Triangle Perimeter
 * Author: Sam Sarsten
 * Date: 01-02-2023
 * Purpose: Compute the perimeter of a triangle placed
 *          on a two-dimensional grid.
 * 
**************************/

#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
};

void get_points(Point[]);
void print_results(Point[]);
float get_perimeter(Point[]);

int main() {
    Point points[3];
    Point points_pos[] = {
        {2, 1}, {3, 4}, {5, 6}
    };
    Point points_neg[] = {
        {-2, -1}, {-3, -4}, {-5, -6}
    };
    Point points_zero[] = {
        {2, 0}, {0, 0}, {0, 6}
    };
    Point points_mix[] = {
        {2, 0}, {-3, -4}, {-5, 0}
    };

    get_points(points);
    
    print_results(points);
    print_results(points_pos);
    print_results(points_neg);
    print_results(points_zero);
    print_results(points_mix);
    
    return 0;
}

void get_points(Point points[])
{
    for (int i = 0; i < 3; i++) {
        cout << "Enter the X coordinate for point " << i + 1 << ": ";
        cin >> points[i].x;
        cout << "Enter the Y coordinate for point " << i + 1 << ": ";
        cin >> points[i].y;
    }

    return;
}

void print_results(Point points[])
{
    float perimeter = get_perimeter(points);

    cout << "Perimeter is: " << perimeter << endl;

    return;
}

float get_perimeter(Point points[])
{
    float perimeter = 0;

    for (int i = 0; i < 3; i++) {
        int delta_x = points[(i + 1) % 3].x - points[i].x;
        int delta_y = points[(i + 1) % 3].y - points[i].y;
        cout << "delta_x: " << delta_x << " delta_y: " << delta_y << endl;
        cout << "sqrt(" << pow(delta_x, 2.0) + pow(delta_y, 2.0) << ")" << endl;
        float length = sqrt(pow(delta_x, 2.0) + pow(delta_y, 2.0));
        cout << "length: " << length << endl;
        perimeter += length;
        cout << "perimeter: " << perimeter << endl;
    }

    return perimeter;
}