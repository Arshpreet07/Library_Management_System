#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "user.h"
#include "transaction.h"
#include<unordered_map>
#include<vector>
#include<mutex>
#include<thread>

class Library{
    //for fast lookups
    std::unordered_map<int,Book> booksMap;
    std::unordered_map<int,User> usersMap;
    std::unordered_map<int,Transaction> transactionsMap;

    //for storing data
    std::vector<Book> books;
    std::vector<User> users;
    std::vector<Transaction> transactions;
    int lastTransactionId;

    //mutex locks
    std::mutex booksMutex;
    std::mutex usersMutex;
    std::mutex transactionsMutex;

public:
    //file management
    bool loadBooksFromFile();
    bool saveBooksToFile();
    bool loadUsersFromFile();
    bool saveUsersToFile();
    bool loadTransactionsFromFile();
    bool saveTransactionsToFile();
    bool loadTransactionId();
    bool saveTransactionId(int lastTransactionId);
    //book management
    void addBook(Book book);
    void removeBook(int bookId);
    Book findBook(int bookId);

    //user management
    void addUser(User user);
    void removeUser(int userId);
    User findUser(int userId);

    //transaction management
    void issueBook(int userId, int bookId);
    void returnBook(int userId, int bookId);
    void recordTransaction(Transaction transaction);

    //helper functions
    std::string getCurrentDate();
    int generateTransactionId();

    //library books
    void displayAllBooks();
    void displayAllUsers();
};

#endif