/*************************
 * Name: Fraction Struct
 * Author: Sam Sarsten
 * Date: 01-08-2022
 * Purpose: Implementing Fraction struct using C++
**************************/

#include <iostream>
using namespace std;

struct Fraction
{
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    int numerator;
    int denominator;
};

void input_fraction(Fraction&);
float compute_decimal(const Fraction&);
bool repeat_program();
void display_fraction(const Fraction&, float);

int main()
{
    do {
        Fraction fraction(0, 0);
        float decimal = 0.0;

        input_fraction(fraction);
        decimal = compute_decimal(fraction);

        display_fraction(fraction, decimal);
    } while (repeat_program());

    cout << "Thanks for using..." << endl;

    return 0;
}

// Get fraction input by user
void input_fraction(Fraction& f)
{
    int denominator = 0;

    cout << "Enter the numerator: ";
    cin >> f.numerator;

    // Validate that denominator is not zero
    while (denominator == 0) {
        cout << "Enter the denominator (can't be 0): ";
        cin >> denominator;
    }
    f.denominator = denominator;

    return;
}

// Returns decimal value of fraction
float compute_decimal(const Fraction& fraction) {
    return static_cast<float>(fraction.numerator) / fraction.denominator;
}

// Quick function to see if user wants to continue
bool repeat_program() {
    char repeat = 'n';
    cout << "Should we repeat the program (Y/N)? ";
    while (repeat != 'Y' && repeat != 'N')
        cin >> repeat;
    return repeat == 'Y';
}

// Display the fraction and decimal versions
void display_fraction(const Fraction& f, float d) {
    cout << "Fraction: " << f.numerator << "/" << f.denominator << endl;
    cout << "Decimal equivalent: " << d << endl;

    return;
}