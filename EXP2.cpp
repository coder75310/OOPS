#include <iostream>
#include <string>
using namespace std;

// Define the structure
struct Student {
    int rollNo;
    string name;
    int age;
    float marks;
};

int main() {
    // Create an array of 10 Student structures
    Student students[10] = {
        {1, "Ankit", 20, 85.5},
        {2, "Ajay", 21, 78.0},
        {3, "Brijesh", 19, 92.3},
        {4, "Akash", 22, 88.1},
        {5, "vipin", 20, 74.5},
        {6, "Tarun", 23, 91.0},
        {7, "kapil", 21, 82.2},
        {8, "Deepak", 19, 67.0},
        {9, "vikas", 20, 95.5},
        {10, "Niraj", 22, 79.0}
    };

    // Display the details of all students
    cout << "Student Details:\n";
    cout << " \n";
    cout << "Roll No\tName\t\tAge\tMarks\n";
    cout << " \n";
    
    for (int i = 0; i < 10; i++) {
        cout << students[i].rollNo << "\t" 
             << students[i].name << "\t\t" 
             << students[i].age << "\t" 
             << students[i].marks << endl;
    }
    
    return 0;
}
