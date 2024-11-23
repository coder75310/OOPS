#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    double rental_price;

public:
    Vehicle(string b, string m, int y, double rp)
        : brand(b), model(m), year(y), rental_price(rp) {}

    double get_rental_cost(int days) {
        return rental_price * days;
    }

    void display() {
        cout << "Brand: " << brand << "\nModel: " << model << "\nYear: " << year << "\nRental Price: " << rental_price << endl;
    }
};

class Car : public Vehicle {
private:
    int number_of_doors;

public:
    Car(string b, string m, int y, double rp, int doors)
        : Vehicle(b, m, y, rp), number_of_doors(doors) {}

    double get_rental_cost(int days){
        double cost = rental_price * days;
        if (days > 7) {
            cost *= 0.95; // 5% discount
        }
        return cost;
    }

    void display(){
        Vehicle::display();
        cout << "Number of Doors: " << number_of_doors << endl;
    }
};

class Motorcycle : public Vehicle {
protected:
    int engine_displacement;

public:
    Motorcycle(string b, string m, int y, double rp, int ed)
        : Vehicle(b, m, y, rp), engine_displacement(ed) {}

    double get_rental_cost(int days){
        double cost = rental_price * days;
        if (days < 3) {
            cost *= 0.90; // 10% discount
        }
        return cost;
    }

    void display(){
        Vehicle::display();
        cout << "Engine Displacement: " << engine_displacement << " cc" << endl;
    }
};

class Bicycle : public Motorcycle {
private:
    string frame_material;

public:
    Bicycle(string b, string m, int y, string fm)
        : Motorcycle(b, m, y, 200, 0), frame_material(fm) {}

    double get_rental_cost(int days){
        return 200 * days; // Fixed rental price
    }

    void display(){
        Vehicle::display();
        cout << "Frame Material: " << frame_material << endl;
    }
};

int main() {
    Car car("Toyota", "Camry", 2020, 50, 4);
    Motorcycle motorcycle("Yamaha", "MT-07", 2021, 30, 689);
    Bicycle bicycle("Giant", "Escape 3", 2022, "Aluminium");

    cout << "Car Rental Cost for 10 days: " << car.get_rental_cost(10) << endl;
    cout << "Motorcycle Rental Cost for 2 days: " << motorcycle.get_rental_cost(2) << endl;
    cout << "Bicycle Rental Cost for 5 days: " << bicycle.get_rental_cost(5) << endl;

    cout << "\nCar Details:\n";
    car.display();
    cout << "\nMotorcycle Details:\n";
    motorcycle.display();
    cout << "\nBicycle Details:\n";
    bicycle.display();

    return 0;
}