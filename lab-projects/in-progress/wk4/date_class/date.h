#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date {
public:
    Date();
    Date(int month, int day, int year);

    int get_month() const;
    int get_day() const;
    int get_year() const;
    void set_month(int month);
    void set_day(int day);
    void set_year(int year);
    void set_date(int month, int day, int year);

    string get_month_name() const;
    int get_julian_date() const;

    private:
        int month, day, year;
        bool is_leap_year(int year) const;
        int get_month_days(int month, int year) const;
};

#endif
