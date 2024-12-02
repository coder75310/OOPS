/* QUESTION
Create a Book class with the following attributes:

book_id (a unique identifier for each book)
title
author
genre
is_available (a boolean indicating whether the book is available for borrowing)
Create a Library class to manage books with the following methods:

add_book(book_id,title, author, genre): Adds a new book to the library.
remove_book(book_id): Removes a book from the library by its ID.
borrow_book(book_id): Marks a book as unavailable when it is borrowed by a library member.
return_book(book_id): Marks a book as available when it is returned by a library member.
list_available_books(): Lists all available books in the library.
list_borrowed_books(): Lists all borrowed books in the library.
 

Implement these classes with proper encapsulation and data validation. Additionally, write a main function to demonstrate the functionality of the Library Management System by creating books, library members, and performing book borrowings and returns.
 */


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    int book_id;
    string title;
    string author;
    string genre;
    bool is_available;

public:
    Book(int id, const string &t, const string &a, const string &g) : book_id(id), title(t), author(a), genre(g), is_available(true) {}

    int getBookID() const { 
        return book_id; 
    }
    string getTitle() const { 
        return title; 
    }
    string getAuthor() const { 
        return author; 
    }
    string getGenre() const { 
        return genre; 
    }
    bool isAvailable() const { 
        return is_available; 
    }

    bool borrow() {
        if (is_available) {
            is_available = false;
            return true;
        }
        return false;
    }

    bool returnBook() {
        if (!is_available) {
            is_available = true;
            return true;
        }
        return false;
    }

    void display() const {
        cout << "Book ID: " << book_id << endl;
        cout << " Title: '" << title << endl;
        cout << " Author: " << author << endl;
        cout << " Genre: " << genre << endl;
        cout << " Available: " << (is_available ? "Yes" : "No") << endl;
    }
};

class Library {
private:
    vector<Book> books;

    int findBookIndex(int id) const {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getBookID() == id) {
                return i;
            }
        }
        return -1;
    }

public:
    void addBook(int id, const string &title, const string &author, const string &genre) {
        if (findBookIndex(id) != -1) {
            cout << "Book with ID " << id << " already exists." << endl;
        } else {
            books.emplace_back(id, title, author, genre);
            cout << "Book added: " << title << endl;
        }
    }

    void removeBook(int id) {
        int index = findBookIndex(id);
        if (index != -1) {
            books.erase(books.begin() + index);
            cout << "Book with ID " << id << " removed from the library." << endl;
        } else {
            cout << "No book found with ID " << id << "." << endl;
        }
    }

    void borrowBook(int id) {
        int index = findBookIndex(id);
        if (index != -1) {
            if (books[index].borrow()) {
                cout << "Book borrowed: " << books[index].getTitle() << endl;
            } else {
                cout << "Book '" << books[index].getTitle() << "' is currently unavailable." << endl;
            }
        } else {
            cout << "No book found with ID " << id << "." << endl;
        }
    }

    void returnBook(int id) {
        int index = findBookIndex(id);
        if (index != -1) {
            if (books[index].returnBook()) {
                cout << "Book returned: " << books[index].getTitle() << endl;
            } else {
                cout << "Book '" << books[index].getTitle() << "' is already marked as available." << endl;
            }
        } else {
            cout << "No book found with ID " << id << "." << endl;
        }
    }

    void listAvailableBooks() const {
        bool found = false;
        for (const auto &book : books) {
            if (book.isAvailable()) {
                book.display();
                found = true;
            }
        }
        if (!found) cout << "No books available." << endl;
    }

    void listBorrowedBooks() const {
        bool found = false;
        for (const auto &book : books) {
            if (!book.isAvailable()) {
                book.display();
                found = true;
            }
        }
        if (!found) cout << "No books currently borrowed." << endl;
    }
};

int main() {
    Library library;

    library.addBook(1, "Data Structure And Algorithms", "Ankit Singh", "C++");
    library.addBook(2, "Object Oriented Programming", "Ajay Singh", "C++");
    library.addBook(3, "Digital Electronics", "Brijesh Shekhawat", "low level languages");
    library.addBook(4, "Software Engineering", "Neeraj Sharma", "Software Design");

    cout << "\nAvailable books:\n";
    library.listAvailableBooks();

    library.borrowBook(1);
    library.borrowBook(3);

    cout << "\nAvailable books after borrowing:\n";
    library.listAvailableBooks();
    cout << "\nBorrowed books:\n";
    library.listBorrowedBooks();

    library.returnBook(1);

    cout << "\nAvailable books after returning:\n";
    library.listAvailableBooks();
    cout << "\nBorrowed books after returning:\n";
    library.listBorrowedBooks();

    library.removeBook(2);

    cout << "\nFinal list of available books:\n";
    library.listAvailableBooks();

    return 0;
}
