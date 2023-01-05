/*************************
 * Name: Date Class
 * Author: Sam Sarsten
 * Date: 01-05-2022
 * Purpose: Implementing Date class using C++
 * Note: Displaying dates in M-D-YYYY format
**************************/

#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 14;
        month = 8;
        year = 1990;
    }

    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    void setDay(int d)
    {
        day = d;
    }

    void setMonth(int m)
    {
        month = m;
    }

    void setYear(int y)
    {
        year = y;
    }

    void setDate(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }
};

int main()
{
    // Let's start by testing the default constructor
    Date date1;
    cout << "Original Dates" << endl << "--------------" << endl;
    cout << "Date 1: " << date1.getMonth() << "-" << date1.getDay() << "-" << date1.getYear() << endl; // My birthday

    // Now test the constructor with parameters
    Date date2(5, 1, 2023);
    cout << "Date 2: " << date2.getMonth() << "-" << date2.getDay() << "-" << date2.getYear() << endl; // Current date

    // Testing the mutator functions
    date1.setDay(6);
    date1.setMonth(1);
    date1.setYear(1967);

    // Testing the setDate mutator
    date2.setDate(14, 12, 1961);

    // Display the results
    cout << endl << "Final Dates" << endl << "-----------" << endl;
    cout << "Date 1: " << date1.getMonth() << "-" << date1.getDay() << "-" << date1.getYear() << endl; // Father's birthday
    cout << "Date 2: " << date2.getMonth() << "-" << date2.getDay() << "-" << date2.getYear() << endl; // Mother's birthay

    return 0;
}
