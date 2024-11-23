#include <iostream>
#include <string>

class Book {
private:
    static int objectCount;  
    static int nextBookID;    
    int bookID;               
    std::string title;

public:

    Book(const std::string& title) : title(title) {
        objectCount++;
        bookID = nextBookID++;
        std::cout << "Book created: " << title << " with ID " << bookID << "\n";
    }

 
    static int getObjectCount() {
        return objectCount;
    }

 
    void display() const {
        std::cout << "Book ID: " << bookID << ", Title: " << title << "\n";
    }
};


int Book::objectCount = 0;
int Book::nextBookID = 1000;

int main() {

    Book book1("The Great Gatsby");
    Book book2("1984");
    Book book3("To Kill a Mockingbird");


    book1.display();
    book2.display();
    book3.display();


    std::cout << "Total objects created: " << Book::getObjectCount() << "\n";

    return 0;
}

