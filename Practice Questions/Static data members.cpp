#include<iostream>
using namespace std;

class Employee
{
    int id;
    static int count; // static int count=1000; - it is a syntax error b/c we cannot write here 1000 but we write 1000 here in sv in "int:: Employee count=1000"

    public:
        void setData(void)
        {
            cout<<"Enter the id"<<endl;
            cin>>id;
            count++;
        }
        void getData(void)    
        {
            cout<<"The id of this employee is " << id << " and this is employee number "<<count<<endl;
        }
        static void getCount(void)
        {
            cout<<id; // throws an error
            cout<<"The value of count is "<<count<<endl;
        }
};

// count is the static data member of class employee
int Employee:: count;   // sv 
// int Employee:: count=1000;
int main()
{
    Employee harry,rohan,lovish;
    // harry.id = 1;
    // harry.count = 1;  // cannot do this as id and count are private
    harry.setData();
    harry.getData();
    Employee::getCount(); // sf run directly in sf or sv not take any reference of any obj.

    rohan.setData();
    rohan.getData();
    Employee::getCount();

    lovish.setData();
    lovish.getData();
    Employee::getCount();

    return 0;
}