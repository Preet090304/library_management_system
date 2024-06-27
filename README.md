# library_management_system
Project Description:
The Library Management System is designed to manage the operations of a library, including adding books, user management, issuing and returning books, and displaying records. The system is implemented in C++ and utilizes various data structures such as vectors and hash maps for efficient management.


1. Introduction

1.1 Objective:
To develop a simple yet functional Library Management System using C++ that demonstrates core concepts of object-oriented programming and data structures.

1.2 Scope:
Adding and managing books
Adding and managing users
Issuing books to users
Returning books from users
Displaying all books and users


2. System Design

2.1 Components:
Book Class: Represents a book with attributes such as title, author, ISBN, and issued status.
User Class: Represents a user with attributes such as name, userID, and borrowed books.
LibraryManagementSystem Class: Manages the collection of books and users, providing functions for adding, issuing, and returning books.

2.2 Data Structures:
Vector: Used for storing books and users.
Unordered Map: Used for quick retrieval of books and users by ISBN and userID, respectively.


3. Testing

3.1 Test Cases:
Adding Books:

Input: ("The Catcher in the Rye", "J.D. Salinger", "123456789")
Expected Output: Book added successfully.
Result: Passed
Adding Users:

Input: ("John Doe", "U001")
Expected Output: User added successfully.
Result: Passed
Issuing Books:

Input: ISBN "123456789" to userID "U001"
Expected Output: Book issued successfully.
Result: Passed
Returning Books:

Input: ISBN "123456789" from userID "U001"
Expected Output: Book returned successfully.
Result: Passed
Displaying All Books and Users:

Expected Output: List of all books and users with their details.
Result: Passed


4. Conclusion

The Library Management System effectively manages library operations, demonstrating proficiency in C++ programming and data structures. The system is robust, user-friendly, and ensures efficient management of books and users.


5. Future Enhancements

Implement search functionality for books and users.
Add support for removing books and users.
Develop a graphical user interface (GUI) for better user interaction.
Integrate a database for persistent storage.



