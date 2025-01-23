#include <iostream>
using namespace std;

// Function prototypes
void deposit(float &balance);
void withdraw(float &balance);
void checkBalance(float &balance);

// Function to deposit money
void deposit(float &balance) {
    float amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    if (amount > 0) {
        balance += amount;
        cout << "Amount deposited: " << amount << endl;
    } else {
        cout << "Invalid amount!" << endl;
    }
}   

// Function to withdraw money
void withdraw(float &balance) {
    float amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Amount withdrawn: " << amount << endl;
    } else {
        cout << "Invalid amount or insufficient funds!" << endl;
    }
}

// Function to check the balance
void checkBalance(float balance) {
    cout << "Current balance: " << balance << endl;
}

int main() {
    float balance = 0.0;
    int choice;

    do {
        cout << "\nBanking Management System\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                deposit(balance);
                break;
            case 2:
                withdraw(balance);
                break;
            case 3:
                checkBalance(balance);
                break;
            case 4:
                cout << "Exiting the system. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
