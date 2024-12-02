#include <iostream>
using namespace std;

class Electricity {
private:
    float units;  // Number of units consumed
    float bill;   // Total bill amount

public:
    // Function to input the number of units
    void inputUnits() {
        cout << "Enter the number of units consumed: ";
        cin >> units;
    }

    // Function to calculate the bill
    void calculateBill() {
        if (units <= 100) {
            bill = units * 1.5;
        } else if (units <= 200) {
            bill = 100 * 1.5 + (units - 100) * 2;
        } else if (units <= 300) {
            bill = 100 * 1.5 + 100 * 2 + (units - 200) * 3;
        } else {
            bill = 100 * 1.5 + 100 * 2 + 100 * 3 + (units - 300) * 4; // Assuming 4 Rs per unit for > 300
        }
    }

    // Function to display the bill
    void displayBill() {
        cout << "Total bill for " << units << " units is: Rs " << bill << endl;
    }
};

int main() {
    Electricity e;
    e.inputUnits();          // Input the number of units consumed
    e.calculateBill();       // Calculate the bill
    e.displayBill();         // Display the bill
    return 0;
}
