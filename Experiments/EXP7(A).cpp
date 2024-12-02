#include <iostream>
#include <string>
using namespace std;

class Identity {
private:
    const string aadhaarID;
    const string address;
    const string panCard;
    const string contactNumber;

public:
    // Constructor to initialize constant data members
    Identity(const string& aadhaar, const string& addr, const string& pan, const string& CN) : aadhaarID(aadhaar), address(addr), panCard(pan), contactNumber(CN) {}

    // Getter functions
    string getAadhaarID() const {  
        return aadhaarID;
    }

    string getAddress() const {
        return address;
    }

    string getPanCard() const {
        return panCard;
    }

    string getContactNumber() const {
        return contactNumber;
    }

    // Display function
    void display() const {
        cout << "Aadhaar ID: " << aadhaarID << "\n"
                  << "Address: " << address << "\n"
                  << "PAN Card: " << panCard << "\n"
                  << "Contact Number: " << contactNumber <<  endl;
    }
};

int main() {
    // Create an Identity object
    Identity person("1234 5678 9012", "123 Main St, Jaipur", "ABCDE1234F", "7296914312");

    // Display the details
    person.display();

    return 0;
}