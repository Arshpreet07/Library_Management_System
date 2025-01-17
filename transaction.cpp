#include "transaction.h"

#include<iostream>
using namespace std;

//constructor
Transaction::Transaction(int transactionId, int userId, int bookId, TransactionType transactionType, string transactionDate) 
: transactionId(transactionId), userId(userId), bookId(bookId), transactionType(transactionType), transactionDate(transactionDate) {}

Transaction::Transaction(const Transaction& other)
        : transactionId(other.transactionId),
          userId(other.userId),
          bookId(other.bookId),
          transactionType(other.transactionType),
          transactionDate(other.transactionDate) {}
//getter functions
int Transaction::getTransactionId() const{
    return transactionId;
}

int Transaction::getUserId() const{
    return userId;
}

int Transaction::getBookId() const{
    return bookId;
}

TransactionType Transaction::getTransactionType() const{
    return transactionType;
}

string Transaction::getTransactionDate() const{
    return transactionDate;
}

//setter functions

void Transaction::setTransactionId(int transactionId){
    this->transactionId = transactionId;
}

void Transaction::setUserId(int userId){
    this->userId = userId;
}

void Transaction::setBookId(int bookId){
    this->bookId = bookId;
}

void Transaction::setTransactionType(TransactionType transactionType){
    this->transactionType = transactionType;
}

void Transaction::setTransactionDate(string transactionDate){
    this->transactionDate = transactionDate;
}

//display transaction information
string Transaction::transactionTypeToString(TransactionType transactionType){
    return (transactionType == TransactionType::Borrow) ? "Borrow" : "Return";
}
void Transaction::displayTransactionInfo(){
    cout<<"Transaction Id : "<<transactionId<<endl;
    cout<<"User Id : "<<userId<<endl;
    cout<<"Book Id : "<<bookId<<endl;
    cout<<"Transaction Type : "<<transactionTypeToString(transactionType)<<endl;
    cout<<"Transaction Date : "<<transactionDate<<endl;
}