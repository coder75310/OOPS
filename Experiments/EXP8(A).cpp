#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int EmployeeID;
    double salary;

public:
    employee(string name, int EmployeeId, double salary){
       this-> name = name;
       this-> EmployeeID = EmployeeID;
       this-> salary = salary;
    }

    double calculateMonthlyPay() {
        return salary;
    }

    // void display() {
        //cout << "Name: " << name << "\nEmployee ID: " << EmployeeID << "\nSalary: " << salary << endl; 
        void display() {
        cout << " Name:\n " << name << endl;
        cout << " Employee ID:\n " << EmployeeID << endl;
        cout << " Salary:\n " << salary << endl;
    }
};

class Professor : public Employee {
private:
    string department;

public:
    Professor(string name, int EmployeeID, double salary, string department)  {
       this-> name = name;
       this-> EmployeeID = EmployeeID;
       this-> salary = salary;
       this-> department = department;
    }

    double calculateMonthlyPay()  {
        return salary + (salary * 0.10); // 10% bonus
    }

    void display() {
        // Employee::display();
        //cout << "Department: " << department << "\nMonthly Pay: " << calculateMonthlyPay() << endl; 
        Employee::display();
        cout << "Department: " << department << endl;
        cout << "\nMonthly Pay: " << calculateMonthlyPay() << endl;
    }
};

class AdminStaff : public Employee {
private:
    string position;

public:
    AdminStaff(string name, int EmployeeID, double salary, string position)  {
       this-> name = name;
       this-> EmployeeID = EmployeeID;
       this-> salary = salary;
       this-> position = position;
    }

    double calculateMonthlyPay() {      
        return salary + (salary * 0.05); // 5% bonus
    }

    void display()  {
        // Employee::display();
        //cout << "Position: " << position << "\nMonthly Pay: " << calculateMonthlyPay() << endl; 
        Employee::display();
        cout << "Position: " << position << endl;
        cout << "\nMonthly Pay: " << calculateMonthlyPay() << endl;
    }
};

class Janitor : public Employee {
private:
    int hoursWorked;

public:
    Janitor(string name, int EmployeeID, int hoursWorkrd) {
       this-> name = name;
       this-> EmployeeID = EmployeeID;
       //this-> salary = salary;
       this-> hoursWorked = hoursWorked;
    }

    double calculateMonthlyPay(){
        return hoursWorked * 5; // Rs 500 per hour
    }

    // void display()  {
       // Employee::display();
       // cout << "Hours Worked: " << hoursWorked << "\nMonthly Pay: " << calculateMonthlyPay() << endl; 
        void display()  {
        Employee::display();
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "\nMonthly Pay: " << calculateMonthlyPay() << endl;
    }
};

int main() {
    Professor prof("Dr. Ankit", 101, 100000, "Computer Science");
    AdminStaff admin("Akash", 102, 50000, "Registrar");
    Janitor janitor("Aryan", 103, 6); // 160 hours worked

    cout << "Professor Details:\n";
    prof.display();
    cout << "\nAdmin Staff Details:\n";
    admin.display();
    cout << "\nJanitor Details:\n";
    janitor.display();

    return 0;
}