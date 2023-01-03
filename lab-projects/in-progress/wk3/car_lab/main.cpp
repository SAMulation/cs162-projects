/*************************
 * Name: Car Class
 * Author: Sam Sarsten
 * Date: 01-03-2022
 * Purpose: Implementing Car class using C++
 * 
**************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Car {
    private:
        // Private variables
        string make;
        string model;
        int number_doors;
        int number_passengers;
        int year;

    public:
        // Default constructor
        Car() : make(""), model(""), number_doors(0), number_passengers(0), year(0) {}

        // Constructor with arguments
        Car(const string& mk, const string& md, int nd, int np, int y)
        : make(mk), model(md), number_doors(nd), number_passengers(np), year(y) {}

        // Accessor functions
        string getMake() const { return make; }
        string getModel() const { return model; }
        int getNumDoors() const { return number_doors; }
        int getNumPassengers() const { return number_passengers; }
        int getYear() const { return year; }

        // Mutator functions
        void setMake(const string& mk) { make = mk; }
        void setModel(const string& md) { model = md; }
        void setNumDoors(int nd) { number_doors = nd; }
        void setNumPassengers(int np) { number_passengers = np; }
        void setYear(int y) { year = y; }
};

int main()
{
    Car my_mustang;  // Create Car object with default constructor
    Car my_camaro("Chevrolet", "Camaro", 2, 2, 2023); // Create Car oject with other constructor

    // Set the member variables using the mutator functions
    my_mustang.setMake("Ford");
    my_mustang.setModel("Mustang");
    my_mustang.setNumDoors(2);
    my_mustang.setNumPassengers(4);
    my_mustang.setYear(2023);

    // Get the member variables using the accessor functions and print them
    cout << left;
    cout << "My Mustang" << endl << "----------" << endl;
    cout << setw(22) << "Make: " << my_mustang.getMake() << endl;
    cout << setw(22) << "Model: " << my_mustang.getModel() << endl;
    cout << setw(22) << "Number of doors: " << my_mustang.getNumDoors() << endl;
    cout << setw(22) << "Number of passengers: " << my_mustang.getNumPassengers() << endl;
    cout << setw(22) << "Year: " << my_mustang.getYear() << endl << endl;
    cout << "My Camaro" << endl << "---------" << endl;
    cout << setw(22) << "Make: " << my_camaro.getMake() << endl;
    cout << setw(22) << "Model: " << my_camaro.getModel() << endl;
    cout << setw(22) << "Number of doors: " << my_camaro.getNumDoors() << endl;
    cout << setw(22) << "Number of passengers: " << my_camaro.getNumPassengers() << endl;
    cout << setw(22) << "Year: " << my_camaro.getYear() << endl;

    return 0;
}
