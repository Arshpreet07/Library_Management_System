#ifndef USER_H
#define USER_H

#include<string> 
#include<vector>
#include<algorithm>

class User{
    //attributes
private:
    int id;
    std::string name;
    std::string contact;
    std::vector<int> borrowedBooks;
public:
    //default constructor
    User();
    //constructor
    User(int id, std::string name, std::string contact, std::vector<int> borrowedBooks);
    
    //setter functions
    void setName(std::string name);
    void setContact(std::string contact);
    
    //getter functions
    int getId() const;
    std::string getName() const;
    std::string getContact() const;
    const std::vector<int>& getBorrowedBooks() const;

    // borrow / return functions
    void addBorrowedBook(int bookId);
    void removeBorrowedBook(int bookId);
    
    //user info
    const void displayUserInfo();
};

#endif