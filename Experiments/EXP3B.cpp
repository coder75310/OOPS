#include <iostream>
#include <string>
#include <vector>

class Patient {
public:
    std::string name;
    int age;
    std::string disease;
    int roomNumber;

    Patient(const std::string& name, int age, const std::string& disease, int roomNumber)
        : name(name), age(age), disease(disease), roomNumber(roomNumber) {}
};

class Hospital {
private:
    std::vector<Patient*> patients; // Use vector to manage dynamic memory

public:
    ~Hospital() {
        // Clean up dynamically allocated memory
        for (auto patient : patients) {
            delete patient;
        }
    }

    void addPatient() {
        std::string name;
        int age;
        std::string disease;
        int roomNumber;

        std::cout << "Enter patient's name: ";
        std::getline(std::cin, name);
        std::cout << "Enter patient's age: ";
        std::cin >> age;
        std::cin.ignore(); // Clear newline character from input buffer
        std::cout << "Enter patient's disease: ";
        std::getline(std::cin, disease);
        std::cout << "Enter patient's room number: ";
        std::cin >> roomNumber;
        std::cin.ignore(); // Clear newline character from input buffer

        // Dynamically allocate a new patient
        Patient* newPatient = new Patient(name, age, disease, roomNumber);
        patients.push_back(newPatient);
        std::cout << "Patient added successfully.\n";
    }

    void displayPatients() const {
        if (patients.empty()) {
            std::cout << "No patients found.\n";
            return;
        }
        std::cout << "\nList of Patients:\n";
        for (const auto& patient : patients) {
            std::cout << "Name: " << patient->name
                      << ", Age: " << patient->age
                      << ", Disease: " << patient->disease
                      << ", Room Number: " << patient->roomNumber << "\n";
        }
    }

    void searchPatient() const {
        std::string name;
        std::cout << "Enter the name of the patient to search: ";
        std::getline(std::cin, name);

        bool found = false;
        for (const auto& patient : patients) {
            if (patient->name == name) {
                std::cout << "Patient found: " 
                          << "Name: " << patient->name 
                          << ", Age: " << patient->age 
                          << ", Disease: " << patient->disease 
                          << ", Room Number: " << patient->roomNumber << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Patient not found.\n";
        }
    }

    void deletePatient() {
        std::string name;
        std::cout << "Enter the name of the patient to delete: ";
        std::getline(std::cin, name);

        for (auto it = patients.begin(); it != patients.end(); ++it) {
            if ((*it)->name == name) {
                delete *it; // Free memory allocated for the patient
                patients.erase(it); // Remove from vector
                std::cout << "Patient deleted successfully.\n";
                return;
            }
        }
        std::cout << "Patient not found.\n";
    }
};

int main() {
    Hospital hospital;
    int choice;

    do {
        std::cout << "\nHospital Patient Management System\n";
        std::cout << "1. Add Patient\n";
        std::cout << "2. Display Patients\n";
        std::cout << "3. Search Patient\n";
        std::cout << "4. Delete Patient\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                hospital.addPatient();
                break;
            case 2:
                hospital.displayPatients();
                break;
            case 3:
                hospital.searchPatient();
                break;
            case 4:
                hospital.deletePatient();
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
