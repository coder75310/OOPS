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
