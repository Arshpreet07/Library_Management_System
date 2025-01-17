#include "user.h"
#include<iostream>
using namespace std;

//default constructor
User::User() : id(0), name(""), contact(""){}

//custom constructor
User::User(int id, string name, string contact, vector<int> borrowedBooks) : id(id), name(name), contact(contact), borrowedBooks(borrowedBooks) {}

//setter functions
void User::setName(string name){
    this->name = name;
}

void User::setContact(string contact){
    this->contact = contact;
}

int User::getId() const{
    return id;
}

string User::getName() const{
    return name;
}

string User::getContact() const{
    return contact;
}

const vector<int>& User::getBorrowedBooks() const{
    return borrowedBooks;
}

//borrow / return functions
void User::addBorrowedBook(int bookId){
    borrowedBooks.emplace_back(bookId);
}

void User::removeBorrowedBook(int bookId){
    auto it = find(borrowedBooks.begin(),borrowedBooks.end(),bookId);
    if(it!=borrowedBooks.end()){
        borrowedBooks.erase(it);
    }
}

//display user information
const void User::displayUserInfo(){
    cout<<"Id : "<<id<<", ";
    cout<<"Name : "<<name<<", ";
    cout<<"Contact : "<<contact<<", ";
    if(borrowedBooks.empty()){
        cout<<"No books borrowed"<<endl;
        return;
    }else{
        cout<<"Books borrowed : ";
        for(size_t i = 0; i<borrowedBooks.size(); i++){
            cout<<borrowedBooks[i];
            if(i != borrowedBooks.size() - 1){
                cout<<", ";
            }
        }
    }
    cout<<endl;
}