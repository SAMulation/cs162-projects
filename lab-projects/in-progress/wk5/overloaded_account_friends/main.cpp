/*************************
 * Name: Overloaded Account
 * Author: Sam Sarsten
 * Date: 01-15-2023
 * Purpose: Implementing overloaded operators for an
 *          Account class using friend functions
 * NOTE: The Account class was not provided, the
 *       following class was inferred by the assignment
**************************/

#include <iostream>
#include <iomanip>
using namespace std;

class Account {
    public:
        // Default constructor
        Account() {
            account_number = 0;
            checking_balance = 0.0;
            savings_balance = 0.0;
        }

        // Overloaded constructor
        Account(const int& a, const double& c, const double& s) : account_number(a), checking_balance(c), savings_balance(s) {}

        // Destructor
        ~Account() {}

        // Accessor functions
        int get_account_number() const { return account_number; }
        double get_checking_balance() const { return checking_balance; }
        double get_savings_balance() const { return savings_balance; }

        // Overloaded = operator
        void operator=(const Account& rhs) {
            account_number = rhs.account_number;
            checking_balance = rhs.checking_balance;
            savings_balance = rhs.savings_balance;
            return;
        }

        // Overloaded == operator
        friend bool operator==(const Account& lhs, const Account& rhs) {
            return lhs.account_number == rhs.account_number;
        }

        // Overloaded < operator
        friend bool operator<(const Account& lhs, const Account& rhs) {
            double account1_total = lhs.checking_balance + lhs.savings_balance;
            double account2_total = rhs.checking_balance + rhs.savings_balance;
            return account1_total < account2_total;
        }

        // Overloaded > operator
        friend bool operator>(const Account& lhs, const Account& rhs) {
            double account1_total = lhs.checking_balance + lhs.savings_balance;
            double account2_total = rhs.checking_balance + rhs.savings_balance;
            return account1_total > account2_total;
        }

        // Overloaded <= operator
        friend bool operator<=(const Account& lhs, const Account& rhs) {
            double account1_total = lhs.checking_balance + lhs.savings_balance;
            double account2_total = rhs.checking_balance + rhs.savings_balance;
            return account1_total <= account2_total;
        }

        // Overloaded >= operator
        friend bool operator>=(const Account& lhs, const Account& rhs) {
            double account1_total = lhs.checking_balance + lhs.savings_balance;
            double account2_total = rhs.checking_balance + rhs.savings_balance;
            return account1_total >= account2_total;
        }
        
    private:
        int account_number;
        double checking_balance;
        double savings_balance;
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