/*************************
 * Name: Student Class Containing Array
 * Author: Sam Sarsten
 * Date: 01-25-2023
 * Purpose: Implementing Student class containing
 *          an array with C++
**************************/

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_COURSES = 7;

struct Name {
    string first;
    string last;
};

struct Course {
    string discipline;
    int number;
};

class Student {
    public:
        // Default constructor
        Student() {
            name = {"", ""};
            idNo = 0;
            numCourses = 0;
        }

        Student(string f, string l) : name({f, l})
        {
            idNo = 0;
            numCourses = 0;
        }

        // Accessor functions
        Name getName() const { return name; }
        int getIdNo() const { return idNo; }
        Course getCourses() { return courses; }

        // Overloaded = operator
        void operator=(const Account& rhs) {
            account_number = rhs.account_number;
            checking_balance = rhs.checking_balance;
            savings_balance = rhs.savings_balance;
        }

        // Overloaded == operator
        bool operator==(const Account& rhs) const {
            return account_number == rhs.account_number;
        }

        // Overloaded < operator
        bool operator<(const Account& rhs) const {
            double account1_total = checking_balance + savings_balance;
            double account2_total = rhs.checking_balance + rhs.savings_balance;
            return account1_total < account2_total;
        }

        // Overloaded > operator
        bool operator>(const Account& rhs) const {
            double account1_total = checking_balance + savings_balance;
            double account2_total = rhs.checking_balance + rhs.savings_balance;
            return account1_total > account2_total;
        }

        // Overloaded <= operator
        bool operator<=(const Account& rhs) const {
            double account1_total = checking_balance + savings_balance;
            double account2_total = rhs.checking_balance + rhs.savings_balance;
            return account1_total <= account2_total;
        }

        // Overloaded >= operator
        bool operator>=(const Account& rhs) const {
            double account1_total = checking_balance + savings_balance;
            double account2_total = rhs.checking_balance + rhs.savings_balance;
            return account1_total >= account2_total;
        }
        
    private:
        Name name;
        int idNo;
        Course courses[MAX_COURSES];
        int numCourses;
};

void testing_functions(const Account&, const Account&);

int main() {
    // Create two Account objects
    Account account1(1111111, 2500, 1000);
    Account account2(2222222, 1500, 500);

    testing_functions(account1, account2); // Should not be equal

    // Test overloaded = operator
    account1 = account2;
    cout << fixed << showpoint << setprecision(2);
    cout << "Account1's account number after using = operator: " << account1.get_account_number() << endl; // Should print 2222222
    cout << "Account1's checking balance after using = operator: $" << account1.get_checking_balance() << endl; // Should print 1500.00
    cout << "Account1's savings balance after using = operator: $" << account1.get_savings_balance() << endl << endl; // Should print 500.00

    testing_functions(account1, account2); // Should be equal

    return 0;
}

void testing_functions(const Account& account1, const Account& account2)
{
    // Test overloaded == operator
    if (account1 == account2) {
        cout << "Account1 and account2 have the same account number" << endl;
    } else {
        cout << "Account1 and account2 have different account numbers" << endl;
    }

    // Test overloaded < operator
    if (account1 < account2) {
        cout << "Account1's total balance is less than account2's total balance" << endl;
    } else {
        cout << "Account1's total balance is not less than account2's total balance" << endl;
    }

    // Test overloaded > operator
    if (account1 > account2) {
        cout << "Account1's total balance is greater than account2's total balance" << endl;
    } else {
        cout << "Account1's total balance is not greater than account2's total balance" << endl;
    }

    // Test overloaded <= operator
    if (account1 <= account2) {
        cout << "Account1's total balance is less than or equal to account2's total balance" << endl;
    } else {
        cout << "Account1's total balance is not less than or equal to account2's total balance" << endl;
    }

    // Test overloaded >= operator
    if (account1 >= account2) {
        cout << "Account1's total balance is greater than or equal to account2's total balance" << endl;
    } else {
        cout << "Account1's total balance is not greater than or equal to account2's total balance" << endl;
    }

    cout << endl;

    return;
}