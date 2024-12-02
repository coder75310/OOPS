#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string account_holder;
    int account_number;
    double balance;

public:
    // Constructor
    BankAccount(string s, int n, double b) {
        account_holder = s;
        account_number = n;
        balance = b;
    }

    // Friend function declaration
    friend void transferFunds(BankAccount &a1, BankAccount &a2, double amount);

    // Display function   
    void display() {
        cout << "Account Holder: " << account_holder << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Friend function definition
void transferFunds(BankAccount &a1, BankAccount &a2, double amount) {
    if (a1.balance >= amount) {
        a1.balance -= amount;
        a2.balance += amount;
        cout << "Transfer successful Transferred " << amount << " from " 
             << a1.account_holder << " to " << a2.account_holder << "." << endl;
    } else {
        cout << "Transfer failed Insufficient balance in " 
             << a1.account_holder << "'s account." << endl;
    }
}

int main() {
    BankAccount account1("Ajay", 101, 5000.0);
    BankAccount account2("Ankit", 102, 300.0);

    account1.display();
    account2.display();

    // Transfer funds
    transferFunds(account1, account2, 4000.0);

    // Display updated accounts
    account1.display();
    account2.display();

    return 0;
}