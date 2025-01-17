#ifndef BOOK_H
#define BOOK_H

#include <string> 

class Book{
    //attributes
private:
    int id;
    std::string title;
    std::string author;
    std::string genre;
    int year;
    bool availability; 

public:
    //default constructor
    Book();
    //constructor
    Book(int id, std::string title, std::string author, std::string genre, int year, bool availability);

    //getter functions
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    int getYear() const;
    bool checkAvailability() const;

    //setter functions
    void setTitle(std::string title);
    void setAuthor(std::string author);
    void setGenre(std::string genre);
    void setYear(int year);
    void updateAvailability(bool availability);

    //display Book information
    const void displayBookInfo();
};

#endif