/*************************
 * Name: Bank Account Class Containing Array
 * Author: Sam Sarsten
 * Date: 01-30-2023
 * Purpose: Implementing bank account class
 *          in C++
**************************/

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    public:
        BankAccount(int id, string name, float balance)
            : accountID(id), accountName(name), balance(balance), depositCounter(0), withdrawalCounter(0) {}

        void deposit(float amount) {
            balance += amount;
            deposits[depositCounter++] = amount;
            return;
        }

        bool withdraw(float amount) {
            if (amount > balance) return false;
            balance -= amount;
            withdrawals[withdrawalCounter++] = amount;
            return true;
        }

        float getBalance() const { return balance; }
        int getAccountID() const { return accountID; }
        string getAccountName() const { return accountName; }

        friend bool operator==(const BankAccount& lhs, const BankAccount& rhs);

        void printInformation() const;
        void printDeposits() const;
        void printWithdrawals() const;

    private:
        int accountID;
        string accountName;
        float balance;
        float deposits[100];
        float withdrawals[100];
        int depositCounter;
        int withdrawalCounter;
};

int main() {
    BankAccount account1(8675309, "Jenny Doe", 1000.0);
    BankAccount account2(8675310, "Jamie Doe", 500.0);

    cout << "Bank Account Class Testing\n"
         << "--------------------------\n\n";

    // Deposit varying amounts
    account1.deposit(100.0);
    account1.deposit(200.0);
    account1.deposit(300.0);
    account1.deposit(400.0);
    account1.deposit(500.0);
    account1.deposit(50.0);
    account2.deposit(100.0);
    account2.deposit(200.0);
    account2.deposit(300.0);
    account2.deposit(400.0);
    account2.deposit(500.0);
    account2.deposit(50.0);

    // Withdraw varying amounts - test failure
    if (!account1.withdraw(200.0)) 
    {
        cout << "Insufficient funds for withdrawal from "
             << account1.getAccountName() << "'s account!\n\n";
    }

    if (!account1.withdraw(400.0)) 
        {
        cout << "Insufficient funds for withdrawal from "
             << account1.getAccountName() << "'s account!\n\n";
    }

    if (!account1.withdraw(6000.0)) 
        {
        cout << "Insufficient funds for withdrawal from "
             << account1.getAccountName() << "'s account!\n\n";
    }

    if (!account2.withdraw(200.0)) 
        {
        cout << "Insufficient funds for withdrawal from "
             << account2.getAccountName() << "'s account!\n\n";
    }

    if (!account2.withdraw(400.0)) 
        {
        cout << "Insufficient funds for withdrawal from "
             << account2.getAccountName() << "'s account!\n\n";
    }

    if (!account2.withdraw(6000.0)) 
        {
        cout << "Insufficient funds for withdrawal from "
             << account2.getAccountName() << "'s account!\n\n";
    }

    // Compare accounts
    if (account1 == account2) {
    cout << "Accounts are the same\n\n";
    } else {
    cout << "Accounts are different\n\n";
    }

    // Print account information
    account1.printInformation();
    account2.printInformation();

    // Print account deposits
    account1.printDeposits();
    account2.printDeposits();

    // Print account withdrawals
    account1.printWithdrawals();
    account2.printWithdrawals();

    return 0;
}

bool operator==(const BankAccount& lhs, const BankAccount& rhs) {
    return lhs.accountID == rhs.accountID;
}

void BankAccount::printInformation() const {
    cout << "Account ID: " << accountID << '\n'
         << "Account Name: " << accountName << '\n'
         << "Balance: $" << balance << "\n\n";
    return;
}

void BankAccount::printDeposits() const {
    cout << "Deposits for Account: " << accountName << '\n';
    for (int i = 0; i < depositCounter; i++)
        cout << (i + 1) << ") $" << deposits[i] << '\n';
    cout << endl;
    return;
    }

void BankAccount::printWithdrawals() const {
    cout << "Withdrawals for Account: " << accountName << '\n';
    for (int i = 0; i < withdrawalCounter; i++)
        cout << (i + 1) << ") $" << withdrawals[i] << '\n';
    cout << endl;
    return;
}
