#include "library.h"

#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

//file management
bool Library::loadBooksFromFile(){
    //BookID|Title|Author|Genre|Year|Availability
    ifstream loading("books.txt");

    if(!loading){
        cerr<<"Error opening books file for reading."<<endl;
        return false;
    }

    string line;

    while(getline(loading,line)){
        int id;
        string title, author, genre, availabilityStr, idStr, yearStr;
        int year;
        bool availability;

        stringstream ss(line);
        getline(ss,idStr,'|');
        getline(ss,title,'|');
        getline(ss,author,'|');
        getline(ss,genre,'|');
        getline(ss,yearStr,'|');
        getline(ss,availabilityStr);

        availability = (availabilityStr == "true");
        
        id = stoi(idStr);
        year = stoi(yearStr);

        Book book(id,title,author,genre,year,availability);
        booksMap[id] = book;
        books.push_back(book);
    }

    loading.close();
    return true;
}

bool Library::saveBooksToFile(){
   //BookID|Title|Author|Genre|Year|Availability
    ofstream saving("books.txt");

    if(!saving){
        cerr<<"Error opening books file for writing."<<endl;
        return false;
    }

    books.clear();
    for (const auto &entry : booksMap) {
        books.push_back(entry.second);
    }

    for(const auto &book : books){
        saving << book.getId() << "|"
               << book.getTitle() << "|"
               << book.getAuthor() << "|"
               << book.getGenre() << "|"
               << book.getYear() << "|"
               << (book.checkAvailability() ? "true" : "false")
               <<endl;
    }

    saving.close();
    return true;
}

bool Library::loadUsersFromFile(){
    //UserID|Name|Contact|BorrowedBooks

    ifstream loading("users.txt");

    if(!loading){
        cerr<<"Error opening users for reading"<<endl;
        return false;
    }

    string line;
    while(getline(loading,line)){
        int id;
        string name, contact, idStr;
        vector<int> borrowedBooks;

        stringstream ss(line);
        
        getline(ss,idStr,'|');
        getline(ss,name,'|');
        getline(ss,contact,'|');

        string bookIdStr;
        while(getline(ss,bookIdStr,',')){
            if(!bookIdStr.empty()) 
                borrowedBooks.emplace_back(stoi(bookIdStr));
        }
        id = stoi(idStr);
        User user(id, name, contact, borrowedBooks);
        usersMap[id] = user;
        users.emplace_back(user);
    }
    loading.close();
    return true;
}

bool Library::saveUsersToFile(){
    //UserID|Name|Contact|BorrowedBooks

    ofstream saving("users.txt");

    if(!saving){
        cerr<<"Error opening users file for writing."<<endl;
        return false;
    }

    users.clear();
    for (const auto &entry : usersMap) {
        users.push_back(entry.second);
    }

    for(const auto &user : users){
        saving << user.getId() << "|"
               << user.getName() << "|"
               << user.getContact() << "|";

        const auto &borrowedBooks = user.getBorrowedBooks();
        for (size_t i = 0; i < borrowedBooks.size(); i++) {
            saving << borrowedBooks[i];
            if (i < borrowedBooks.size() - 1) {
                saving << ",";
            }
        }
    }

    saving.close();
    return true;
}

bool Library::loadTransactionsFromFile(){
    //TransactionID|UserID|BookID|TransactionDate|TransactionType

    ifstream loading("transactions.txt");

    if(!loading){
        cerr<<"Error opening transactions for reading"<<endl;
        return false;
    }

    string line;
    while(getline(loading,line)){
        if (line.empty()) continue;
        int transactionId, userId, bookId;
        string transactionDate, typeStr, transactionIdStr, userIdStr, bookIdStr;
        TransactionType transactionType;

        stringstream ss(line);
        getline(ss,transactionIdStr,'|');
        getline(ss,userIdStr,'|');
        getline(ss,bookIdStr,'|');
        getline(ss,transactionDate,'|');
        getline(ss,typeStr,'|');

        transactionType = (typeStr == "Borrow"? TransactionType::Borrow : TransactionType::Return);
        transactionId = stoi(transactionIdStr);
        bookId = stoi(bookIdStr);
        userId = stoi(userIdStr);
        Transaction transaction(transactionId, userId, bookId, transactionType, transactionDate);
        transactions.emplace_back(transaction);
        transactionsMap.emplace(transaction.getTransactionId(), transaction);
    }

    loading.close();
    return true;
}

bool Library::saveTransactionsToFile(){
    //TransactionID|UserID|BookID|TransactionDate|TransactionType

    ofstream saving("transactions.txt");

    if(!saving){
        cerr<<"Error opening transactions file for writing."<<endl;
        return false;
    }

    for(const auto &transaction : transactions){
        saving << transaction.getTransactionId() << '|'
               << transaction.getUserId() << '|'
               << transaction.getBookId() << '|'
               << transaction.getTransactionDate() << '|'
               << (transaction.getTransactionType() == TransactionType::Borrow ? "Borrow" : "Return")
               << endl;
    }
    saving.close();
    return true;
}
bool Library::loadTransactionId(){
    ifstream loading("transactionId.txt");

    if(!loading){
        lastTransactionId = 0;
        return false;
    }

    string line;
    getline(loading,line);
    if(line.empty()){
        lastTransactionId = 0;
        return false;
    }

    lastTransactionId = stoi(line);
    loading.close();
    return true;
}

bool Library::saveTransactionId(int lastTransactionId){
    ofstream saving("transactionId.txt");
    if(!saving){
        cerr<<"Error opening transactionsId file for writing."<<endl;
        return false;
    }

    saving << lastTransactionId;

    saving.close();
    return true;
}

//books management
void Library::addBook(Book book){
    if(booksMap.find(book.getId()) != booksMap.end()){
        cerr << "Book with ID " << book.getId() << " Already exists." << endl;
        return;
    }
    books.emplace_back(book);
    booksMap[book.getId()] = book;
    cout << "Book added successfully!" << endl;
}

void Library::removeBook(int bookId){
    if(booksMap.find(bookId) == booksMap.end()){
        cerr << "Book with ID " << bookId << " not found." << endl;
        return;
    }

    booksMap.erase(bookId);

    for(auto it = books.begin(); it!=books.end(); it++){
        if(it->getId() == bookId){
            books.erase(it);
            cout << "Book removed successfully!" << endl;
            return;
        }
    }

}

Book Library::findBook(int bookId){
    auto it = booksMap.find(bookId);
    if(it != booksMap.end()){
        return it->second;
    }
    throw runtime_error("Book with the given ID not found.");
}

//Users management
void Library::addUser(User user){
    if(usersMap.find(user.getId()) != usersMap.end()){
        cerr << "User with ID " << user.getId() << " Already exists." << endl;
        return;
    }
    users.emplace_back(user);
    usersMap[user.getId()] = user;
    cout << "User added successfully!" << endl;
}

void Library::removeUser(int userId){
    usersMap.erase(userId);

    for(auto it = users.begin(); it!=users.end(); it++){
        if(it->getId() == userId){
            users.erase(it);
            cout << "User removed successfully!" << endl;
            return;
        }
    }
    cout << "User with ID " << userId << " not found." << endl;
}

User Library::findUser(int userId){
    auto it = usersMap.find(userId);

    if(it != usersMap.end()){
        return it->second;
    }
    
    throw runtime_error("User with the given ID not found.");
}

//transactions management
void Library::issueBook(int userId, int bookId){
    lock_guard<mutex> booksLock(booksMutex);
    lock_guard<mutex> usersLock(usersMutex);
    auto userIt = usersMap.find(userId);
    auto bookIt = booksMap.find(bookId);

    if(userIt == usersMap.end()){
        cout << "User not found!" << endl;
        return;
    }
    if(bookIt == booksMap.end()){
        cout << "Book not found!" << endl;
        return;
    }
    User &user = userIt->second;
    Book &book = bookIt->second;

    if(!book.checkAvailability()){
        cout << "Book is not currently available!" << endl;
        return;
    }

    book.updateAvailability(false);
    user.addBorrowedBook(bookId);

    {
        lock_guard<mutex> transactionsLock(transactionsMutex);
        Transaction transaction(generateTransactionId(), userId, bookId, TransactionType::Borrow,  getCurrentDate());
        recordTransaction(transaction);
    }

    cout<< "Book issued successfully!" << endl;
}

void Library::returnBook(int userId, int bookId){
    lock_guard<mutex> booksLock(booksMutex);
    lock_guard<mutex> usersLock(usersMutex);
    auto userIt = usersMap.find(userId);
    auto bookIt = booksMap.find(bookId);

    if(userIt == usersMap.end()){
        cout << "User not found!" << endl;
        return;
    }
    if(bookIt == booksMap.end()){
        cout << "Book not found!" << endl;
        return;
    }
    User &user = userIt->second;
    Book &book = bookIt->second;
    
    vector<int> borrowedBooks = user.getBorrowedBooks();
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
    if(it == borrowedBooks.end()){
        cout << "User has not borrowed this book!" << endl;
        return;
    }

    book.updateAvailability(true);
    user.removeBorrowedBook(bookId);
    {   
        lock_guard<mutex> transactionsLock(transactionsMutex);
        Transaction transaction(generateTransactionId(), userId, bookId, TransactionType::Return, getCurrentDate());
        recordTransaction(transaction);
    }
    cout<< "Book returned successfully!" << endl;
}

void Library::recordTransaction(Transaction transaction){
    transactionsMap.emplace(transaction.getTransactionId(), transaction);
    transactions.emplace_back(transaction);
}

string Library::getCurrentDate(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return string(buf);
}

int Library::generateTransactionId(){
    static int transactionIdCounter = lastTransactionId;
    ++transactionIdCounter;
    saveTransactionId(transactionIdCounter);
    return transactionIdCounter;
}

//library info
void Library::displayAllBooks(){
    for(auto &book : books){
        book.displayBookInfo();
    }
}

void Library::displayAllUsers(){
    for(auto &user : users){
        user.displayUserInfo();
    }
}