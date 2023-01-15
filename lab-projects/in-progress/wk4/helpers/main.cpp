/*************************
 * Name: Employee class
 * Author: Sam Sarsten
 * Date: 01-14-2022
 * Purpose: Creating helper functions to
 *          validate employee data
**************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

class Employee {
    private:
        // Private variables
        string first;
        string last;
        string email;
        string phone;

    public:
        // Default constructor
        Employee();

        // Constructor with arguments for last name and email only
        Employee(const string&, const string&);

        // Accessor functions
        string get_first() const { return first; }
        string get_last() const { return last; }
        string get_email() const { return email; }
        string get_phone() const { return phone; }

        // Mutator functions
        void set_first(const string&);
        void set_last(const string&);
        void set_email(const string&);
        void set_phone(const string&);

        // Helper functions
        bool validate_name(const string&) const;

        bool validate_num(const string& f) const;

        bool validate_email(const string& f) const;

        bool validate_phone(const string& p) const;
};

int main()
{
    Employee employee1;  // Create Employee object with default constructor
    Employee employee2("Barker", "alice.barker@gmail.com"); // Create Employee object with other constructor

    // Set the member variables using the mutator functions
    employee1.set_first("John");
    employee1.set_last("Smith");
    employee1.set_email("john.smith@yahoo.com");
    employee1.set_phone("5415551234");
    employee2.set_first("Alice");
    employee2.set_phone("5035551234");

    // Set the member variables using the mutator functions with invalid input
    // None of these values should be set
    employee2.set_first("John123");
    employee2.set_last("Smith123");
    employee2.set_email("johnsmith@yahoocom");
    employee2.set_email("john.smith@yahoocom");
    employee2.set_email("john.smith.yahoo.com");
    employee2.set_phone("54155512341");

    // Get the member variables using the accessor functions and print them
    cout << left;
    cout << "Employee 1 (John Smith, john.smith@yahoo.com, 5415551234)" << endl << "----------" << endl;
    cout << setw(22) << "Name: " << employee1.get_first() << " " << employee1.get_last() << endl;
    cout << setw(22) << "Email: " << employee1.get_email() << endl;
    cout << setw(22) << "Phone: " << employee1.get_phone() << endl;
    cout << endl;
    cout << "Employee 2 (Alice Barker, alice.barker@gmail.com, 5035551234)" << endl << "---------" << endl;
    cout << setw(22) << "Name: " << employee2.get_first() << " " << employee2.get_last() << endl;
    cout << setw(22) << "Email: " << employee2.get_email() << endl;
    cout << setw(22) << "Phone: " << employee2.get_phone() << endl;
    cout << "*** Notice that Alice's info was not updated with invalid input ***" << endl;

    return 0;
}

// Default constructor
Employee::Employee()
{
    first = "";
    last = "";
    email = "";
    phone = "";
}

 // Constructor with arguments for last name and email only
Employee::Employee(const string& l, const string& e)
{
    first = "";
    last = l;
    email = e;
    phone = "";
}

// Mutator functions
void Employee::set_first(const string& f)
{
    if (Employee::validate_name(f))
        first = f;
    return;
}
void Employee::set_last(const string& l)
{
    if (Employee::validate_name(l))
        last = l;
    return;
}
void Employee::set_email(const string& e)
{
    if (Employee::validate_email(e))
        email = e;
    return;
}
void Employee::set_phone(const string& p)
{
    if (Employee::validate_phone(p))
        phone = p;
    return;
}

// Helper functions
bool Employee::validate_name(const string& f) const
{
    bool isChar = true;
    for (int i = 0; i < f.length() && isChar; i++)
    {
        if (!isalpha(f.at(i)))
            isChar = false;
    }
    return isChar;
}

bool Employee::validate_num(const string& f) const
{
    bool isDig = true;
    for (int i = 0; i < f.length() && isDig; i++)
    {
        if (!isdigit(f.at(i)))
            isDig = false;
    }
    return isDig;
}

bool Employee::validate_email(const string& f) const
{
    bool isValid = true;
    int atPos = -1;
    int lastPeriod = -1;

    for (int i = 0; i < f.length() && isValid; i++)
    {
        // First check if char or digit
        if (!isalpha(f.at(i)) && !isdigit(f.at(i)))
        {
            // Check at
            if (f.at(i) == '@')
            {
                // Does it exist?
                if (atPos != -1)
                    // Too many
                    isValid = false;
                // First encounter, store
                else
                    atPos = i;
            }
            // Store latest period
            else if (f.at(i) == '.')
                lastPeriod = i;
            else
                isValid = false;
        }
    }

    // Only check if never hit invalid character
    // Checking for other invalid states
    if (isValid)
    {
        // Never found at
        if (atPos == -1)
            isValid = false;
        
        // Never found period
        if (lastPeriod == -1)
            isValid = false;
        // The last period is before the at
        else if (lastPeriod < atPos)
            isValid = false;
    }

    return isValid;
}

bool Employee::validate_phone(const string& p) const
{
    // Must be 10 characters
    bool validPhone = p.length() == 10;
    if (validPhone)
        validPhone = validate_num(p);

    return validPhone;
}
