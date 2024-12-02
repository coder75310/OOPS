#include<iostream>
using namespace std;

class complex{

    private:
        double real; 
        double imaginary;

    public:
        complex() : real(0), imaginary(0) {}

        complex(double r, double i) : real(r), imaginary(i){} 

        complex operator +(const complex& obj) const{

            return complex(real+obj.real, imaginary+obj.imaginary);
        }

        complex operator -(const complex& obj) const{

            return complex(real-obj.real,imaginary-obj.imaginary);
        }

        friend istream& operator>>(istream& cin, complex& c){

            cout << "Enter real part: ";
            cin>>c.real;
            cout<< "Enter imaginary part: ";
            cin>>c.imaginary;

            return cin;
        }

        friend ostream& operator <<(ostream& cout, const complex& c){

            cout<<c.real<< " + " <<c.imaginary << "i";
            return cout;
        }
};

int main(){

    complex c1,c2;

    cout << "Enter first complex number: "<<endl;
    cin>>c1;
    cout << "Enter second complex number: "<<endl;
    cin>>c2;

    complex sum = c1+c2;
    complex diff = c1-c2;

    cout<<"Sum of complex number "<<sum<<endl;
    cout<<"Difference of complex number"<<diff<<endl;

    return 0;
}