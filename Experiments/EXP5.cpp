#include<iostream>
#include<string>
using namespace std;

class student{
    string name;
    int roll_Number;
    float marks;

    public:
        student()
        {
            name = " ";
            roll_Number = 0;
            marks = 0.0;
        }

        student(string n, int r, float m)
        {
            name = n;
            roll_Number = r;
            marks = m;
        }

        student(student &s)
        {
            name = s.name;
            roll_Number = s.roll_Number;
            marks = s.marks;
        }

        void display() const{
            cout<< "Name:"<< name<<endl;
            cout<< "roll_Number:"<<roll_Number<<endl;
            cout<< "marks:"<<marks<<endl;
        }
};

int main()
{
    student student1;
    cout<< "student1 (Default constructor):"<<endl;
    student1.display();

    student student2("ankit" , 18 , 95.5);
    cout<< "student2 (paramaterised Constructor):"<<endl;
    student2.display();

    student student3(student2);
    cout<< "student3 (copy constructor):"<<endl;
    student3.display();

    return 0;
}