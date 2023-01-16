/*************************
 * Name: Country ADT
 * Author: Sam Sarsten
 * Date: 01-15-2023
 * Purpose: Implementing Country class using C++
 *          includes helper functions to copy Country
 *          and find the largest Country (of three)
**************************/

#include <iostream>
#include <cmath>
using namespace std;

class Country {


    public:
        // Default constructor
        Country() {
            name = "";
            capital = "";
            population = 0;
        }

        // Overloaded constructor
        Country(const string& n, const string& c, const int& p) : name(n), capital(c), population(p) {}

        // Destructor
        ~Country() {}

        // Accessor and mutator functions
        string get_name() const { return name; }
        string get_capital() const { return capital; }
        int get_population() const { return population; }
        void set_name(const string& n) { name = n; return; }
        void set_capital(const string& c) { capital = c; return; }
        void set_population(const int& p) { population = p; return; }

        // Predict future population at 1.05% growth rate per year
        float future_population()
        {
            float growth_rate = 1.05;
            return population * pow(1 + growth_rate / 100, 10.0);
        }

        Country largest_country(const Country& c2, const Country& c3)
        {
            int c1_pop = get_population();
            int c2_pop = c2.get_population();
            int c3_pop = c3.get_population();

            if (c1_pop > c2_pop && c1_pop > c3_pop)
                return *this;
            else if (c2_pop > c3_pop)
                return c2;
            else
                return c3;
        }
        
    private:
        string name;
        string capital;
        int population;
};

void populate_country(Country&);
void print_country(const Country&);
Country copy_country(const Country&);

int main()
{
    // Create 5 Country objects
    Country c1;
    Country c2;
    Country c3;
    Country c4;
    Country largest;

    // Populate 3 Country objects with values from user input
    populate_country(c1);
    populate_country(c2);
    populate_country(c3);

    // Print the values of the Country objects
    cout << endl << "Country 1: " << endl;
    print_country(c1);
    cout << "Country 2: " << endl;
    print_country(c2);
    cout << "Country 3: " << endl;
    print_country(c3);

    // Make a copy of the first Country object
    c4 = copy_country(c1);
    cout << "Country 4: " << endl;
    print_country(c4);

    // Test the function that predicts population increase
    cout << "The population of country 1 in 10 years is predicted to be: " << c1.future_population() << endl;

    // Test the function that returns the country with largest population
    largest = c1.largest_country(c2, c3);
    cout << "The country with the largest population is: " << largest.get_name() << endl;

    return 0;
}

void populate_country(Country& country)
{
    string n, c;
    int p;
    cout << "Enter the name of the country: ";
    getline(cin, n);
    cout << "Enter the capital of the country: ";
    getline(cin, c);
    cout << "Enter the population of the country: ";
    cin >> p;
    cin.ignore(80, '\n');
    country.set_name(n);
    country.set_capital(c);
    country.set_population(p);
    return;
}

void print_country(const Country& country)
{
    cout << "Name: " << country.get_name() << endl;
    cout << "Capital: " << country.get_capital() << endl;
    cout << "Population: " << country.get_population() << endl << endl;
    return;
}

Country copy_country(const Country& c) {
    Country newCountry(c.get_name(), c.get_capital(), c.get_population());
    return newCountry;
}