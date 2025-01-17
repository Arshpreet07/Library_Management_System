#include "book.h"
#include<iostream>
using namespace std;

//default constructor
Book::Book() : id(0), title(""), author(""), genre(""), year(0), availability(true) {}

//constructor with all values
Book::Book(int id,  string title, string author, string genre, int year, bool availability) : id(id), title(title), author(author), genre(genre), year(year), availability(availability) {}

//getter functions
int Book::getId() const{
    return id;
}

string Book::getTitle() const{
    return title;
}

string Book::getAuthor() const{
    return author;
}

string Book::getGenre() const{
    return genre;
}

int Book::getYear() const{
    return year;
}

bool Book::checkAvailability() const{
    return availability;
}

//setter functions
void Book::setAuthor(string author){
    this->author = author;
}

void Book::setTitle(string title){
    this->title = title;
}

void Book::setGenre(string genre){
    this->genre = genre;
}

void Book::setYear(int year){
    this->year = year;
}

void Book::updateAvailability(bool availability){
    this->availability = availability;
}

//display function
const void Book::displayBookInfo(){
    cout<<"Book id : "<<id<<", ";
    cout<<"Title : "<<title<<", ";
    cout<<"Author : "<<author<<", ";
    cout<<"Genre : "<<genre<<", ";
    cout<<"Year : "<<year<<", "; 
    cout<<"Availability : "<< ( availability?  "Available" : "Not Available")<<endl;
}