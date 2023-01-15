#include "date.h"
#include <iostream>
#include <string>
using namespace std;

Date::Date() {
    month = 0;
    day = 0;
    year = 0;
}

Date::Date(int month, int day, int year) {
    set_date(month, day, year);
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}

int Date::get_year() const {
    return year;
}

// Mutator functions
void Date::set_month(int m) {
    month = m;
}

void Date::set_day(int d) {
    day = d;
}

void Date::set_year(int y) {
    year = y;
}

void Date::set_date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

// Other functions
string Date::get_month_name() const {
    string monthNames[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    return monthNames[month - 1];
}

int Date::get_julian_date() const {
    int julianDate = day;

    // Keep adding number of days in a month
    // Until the specified month is hit
    for (int i = 1; i < month; i++) {
        julianDate += get_month_days(i, year);
    }

    return julianDate;
}

bool Date::is_leap_year(int year) const {
    if (year % 4 != 0) {
        return false;
    }
    else if (year % 100 != 0) {
        return true;
    }
    else if (year % 400 != 0) {
        return false;
    }
    else {
        return true;
    }
}

int Date::get_month_days(int month, int year) const {
    int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Checking for leap year here
    if (month == 2 && is_leap_year(year)) {
        return 29; // Return odd 29 for Feb here
    }
    else {
        return monthDays[month - 1]; // Return what is stored in array
    }
}
