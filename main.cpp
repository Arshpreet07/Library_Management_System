#include <iostream>
#include <string>
#include "library.h"

using namespace std;

void displayMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. View All Books\n";
    cout << "2. Add a Book\n";
    cout << "3. Remove a Book\n";
    cout << "4. Borrow a Book\n";
    cout << "5. Return a Book\n";
    cout << "6. View Users\n";
    cout << "7. Add User\n";
    cout << "8. Remove User\n";
    cout << "9. Simulate Concurrent Operations\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Library library;
    if (!library.loadBooksFromFile()) {
        cout << "Failed to load books data.\n";
    }
    if (!library.loadUsersFromFile()) {
        cout << "Failed to load users data.\n";
    }
    if (!library.loadTransactionsFromFile()) {
        cout << "Failed to load transactions data.\n";
    }
    if(!library.loadTransactionId()){
        cout<< "Transaction Id set to 0"<<endl;
    }

    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nDisplaying all books:\n";
                library.displayAllBooks();
                break;
            }
            case 2: {
                int id, year;
                string title, author, genre;
                bool availability;

                cout << "\nEnter book details:\n";
                cout << "ID: "; cin >> id;
                cout << "Title: "; cin.ignore(); getline(cin, title);
                cout << "Author: "; getline(cin, author);
                cout << "Genre: "; getline(cin, genre);
                cout << "Year: "; cin >> year;
                cout << "Availability (1 for Available, 0 for Not Available): "; cin >> availability;

                Book book(id, title, author, genre, year, availability);
                library.addBook(book);

                library.saveBooksToFile();
                break;
            }
            case 3: {
                int bookId;
                cout << "Enter book ID to remove: ";
                cin >> bookId;

                library.removeBook(bookId);
                library.saveBooksToFile();
                break;
            }
            case 4: {
                int userId, bookId;
                cout << "Enter user ID: ";
                cin >> userId;
                cout << "Enter book ID to borrow: ";
                cin >> bookId;

                library.issueBook(userId, bookId);
                library.saveBooksToFile();
                library.saveUsersToFile();
                library.saveTransactionsToFile();
                break;
            }
            case 5: {
                int userId, bookId;
                cout << "Enter user ID: ";
                cin >> userId;
                cout << "Enter book ID to return: ";
                cin >> bookId;

                library.returnBook(userId, bookId);
                library.saveBooksToFile();
                library.saveUsersToFile();
                library.saveTransactionsToFile();
                break;
            }
            case 6: {
                cout << "\nDisplaying all users:\n";
                library.displayAllUsers();
                break;
            }
            case 7: {
                int id;
                string name, contact;
                cout << "\nEnter user details:\n";
                cout << "ID: "; cin >> id;
                cout << "Name: "; cin.ignore(); getline(cin, name);
                cout << "Contact: "; getline(cin, contact);

                User user(id, name, contact, vector<int>());
                library.addUser(user);
                library.saveUsersToFile();
                break;
            }
            case 8: {
                int userId;
                cout << "Enter user ID to remove: ";
                cin >> userId;

                library.removeUser(userId);
                library.saveUsersToFile();
                break;
            }
            case 9: {
                int op1UserId, op1BookId, op2UserId, op2BookId;
                char op1Type, op2Type;

                cout << "Enter details for first operation:\n";
                cout << "Operation Type (B for Borrow, R for Return): ";
                cin >> op1Type;
                cout <<"User ID: ";
                cin >> op1UserId;
                cout <<"Book ID: ";
                cin >> op1BookId;

                cout << "Enter details for second operation:\n";
                cout << "Operation Type (B for Borrow, R for Return): ";
                cin >> op2Type;
                cout <<"User ID: ";
                cin >> op2UserId;
                cout <<"Book ID: ";
                cin >> op2BookId;
                cout<<endl;
                
                thread t1, t2;

                if(op1Type == 'B' || op1Type == 'b'){
                    t1 = thread(&Library::issueBook, &library, op1UserId, op1BookId);
                }else if(op1Type == 'R' || op1Type == 'r'){
                    t1 = thread(&Library::returnBook, &library, op1UserId, op1BookId);
                }

                if(op2Type == 'B' || op2Type == 'b'){
                    t2 = thread(&Library::issueBook, &library, op2UserId, op2BookId);
                }else if(op2Type == 'R' || op2Type == 'r'){
                    t2 = thread(&Library::returnBook, &library, op2UserId, op2BookId);
                }

                if(t1.joinable()) t1.join();
                if(t2.joinable()) t2.join();

                library.saveBooksToFile();
                library.saveUsersToFile();
                library.saveTransactionsToFile();

                cout<< "\nConcurrent operations simulated successfully!"<<endl;
                break;
            }
            case 0: {
                cout << "Exiting the system. Goodbye!\n";
                running = false;
                break;
            }
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
    return 0;
}
