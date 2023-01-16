/*************************
 * Name: Date class
 * Author: Sam Sarsten
 * Date: 01-09-2023
 * Purpose: Implementing Date class using C++
**************************/

#include "date.h"
#include <iostream>
using namespace std;

int main() {
    Date today;
    today.set_date(1, 9, 2023);

    cout << "This program was developed on: " << today.get_month_name() << " " << today.get_day() << ", " << today.get_year() << endl;
    cout << "The Julian date on that day was: " << today.get_julian_date() << endl;
    return 0;
}
