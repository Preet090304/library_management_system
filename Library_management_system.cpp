#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool isIssued;

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), isIssued(false) {}
};

class User {
public:
    string name;
    string userID;
    vector<string> borrowedBooks;

    User(string n, string id) : name(n), userID(id) {}
};

class LibraryManagementSystem {
private:
    vector<Book> books;
    vector<User> users;
    unordered_map<string, Book*> bookMap; // ISBN -> Book pointer
    unordered_map<string, User*> userMap; // userID -> User pointer

public:
    void addBook(string title, string author, string ISBN) {
        Book newBook(title, author, ISBN);
        books.push_back(newBook);
        bookMap[ISBN] = &books.back();
    }

    void addUser(string name, string userID) {
        User newUser(name, userID);
        users.push_back(newUser);
        userMap[userID] = &users.back();
    }

    void issueBook(string ISBN, string userID) {
        if (bookMap.find(ISBN) == bookMap.end()) {
            cout << "Book not found." << endl;
            return;
        }
        if (userMap.find(userID) == userMap.end()) {
            cout << "User not found." << endl;
            return;
        }

        Book* book = bookMap[ISBN];
        User* user = userMap[userID];

        if (book->isIssued) {
            cout << "Book is already issued." << endl;
            return;
        }

        book->isIssued = true;
        user->borrowedBooks.push_back(ISBN);
        cout << "Book issued successfully." << endl;
    }

    void returnBook(string ISBN, string userID) {
        if (bookMap.find(ISBN) == bookMap.end()) {
            cout << "Book not found." << endl;
            return;
        }
        if (userMap.find(userID) == userMap.end()) {
            cout << "User not found." << endl;
            return;
        }

        Book* book = bookMap[ISBN];
        User* user = userMap[userID];

        auto it = find(user->borrowedBooks.begin(), user->borrowedBooks.end(), ISBN);
        if (it == user->borrowedBooks.end()) {
            cout << "This user did not borrow this book." << endl;
            return;
        }

        user->borrowedBooks.erase(it);
        book->isIssued = false;
        cout << "Book returned successfully." << endl;
    }

    void displayAllBooks() {
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN << ", Issued: " << (book.isIssued ? "Yes" : "No") << endl;
        }
    }

    void displayAllUsers() {
        for (const auto& user : users) {
            cout << "Name: " << user.name << ", UserID: " << user.userID << ", Borrowed Books: ";
            for (const auto& isbn : user.borrowedBooks) {
                cout << isbn << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    LibraryManagementSystem lms;

    lms.addBook("The Catcher in the Rye", "J.D. Salinger", "123456789");
    lms.addBook("To Kill a Mockingbird", "Harper Lee", "987654321");
    lms.addUser("John Doe", "U001");
    lms.addUser("Jane Smith", "U002");

    lms.issueBook("123456789", "U001");
    lms.returnBook("123456789", "U001");

    cout << "Books in the library:" << endl;
    lms.displayAllBooks();

    cout << "Users in the library:" << endl;
    lms.displayAllUsers();

    return 0;
}
