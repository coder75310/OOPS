/* QUESTION
Problem Statement:

You are building a basic inventory management system for a store that sells various items. In this system, we will represent products using a hierarchy of classes.

Base Class: Product

Create a base class Product with the following attributes:
productID (int): The unique ID for the product.
name (string): The name of the product.
price (float): The price of the product.
Add the following member functions:
A constructor that initializes productID, name, and price.
A virtual function displayProductDetails() that prints the details of the product.
Derived Class: Electronics

Create a derived class Electronics that inherits from Product.
Add additional attributes specific to electronics:
warrantyPeriod (int): The warranty period in years.
Override the displayProductDetails() function to include the warranty period of the electronic product.
Derived Class: Furniture

Create another derived class Furniture that also inherits from Product.
Add additional attributes specific to furniture:
materialType (string): The type of material used (e.g., wood, metal).
Override the displayProductDetails() function to include the type of material used for the furniture.
Demonstrate Polymorphism:

In the main function, create an array of pointers to Product and populate it with objects of Electronics and Furniture.
Iterate through the array and call the displayProductDetails() method for each object, demonstrating runtime polymorphism.
Expected Output:
Product Info: ID = 101, Name = Smartphone, Price = 500.00, Warranty = 2 years Product Info: ID = 202, Name = Sofa, Price = 300.00, Material = Wood
 */



#include <iostream>
#include <vector>
using namespace std;

class Product{
    protected:
        int productID;
        string name;
        float price;

    public:
        Product(int id, const string &n, float p ) : productID(id), name(n), price(p) {}

        virtual void displayProductDetails() const{
            cout << "Product ID: " << productID << endl;
            cout << "Name: " << name << endl;
            cout << "Price: $" << price << endl;
        }

        virtual ~Product() {} 
};

class Electronics : public Product{
    private:
        int warrantyPeriod;
    
    public:
        Electronics(int id, const string &n, float p, int w) : Product(id, n, p), warrantyPeriod(w) {}

        void displayProductDetails() const override{
        Product :: displayProductDetails();
        cout <<" Warranty Period: " << warrantyPeriod << " years " << endl;
    }
};

class Furniture : public Product{
    private:
        string materialType;

    public:
        Furniture(int id, const string &n, float p, const string &m ) : Product(id, n, p), materialType(m) {}

        void displayProductDetails() const override{
        Product :: displayProductDetails();
        cout <<" Material Type: " << materialType << endl;
    }
};

int main(){
    vector<Product*> inventory;

    inventory.push_back(new Electronics(1, "Laptop", 100, 1));
    inventory.push_back(new Furniture(2, "bed", 299, "wood"));
    inventory.push_back(new Electronics(3, "smart phone", 999, 1));
    inventory.push_back(new Furniture(4, "Sofa", 50, "Leather"));

    for(const auto &product : inventory){
        product-> displayProductDetails();
        cout << " " << endl;
    }

    for(const auto &Product : inventory){
        delete Product;
    }

    return 0;

} 