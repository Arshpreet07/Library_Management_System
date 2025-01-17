#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<string>

enum class TransactionType{
    Borrow,
    Return
};

class Transaction{
    //attributes
private:
    int transactionId;
    int userId;
    int bookId;
    std::string transactionDate;
    TransactionType transactionType;
    
    static std::string transactionTypeToString(TransactionType transactionType);
    //methods
public:
    //constructor
    Transaction(int transactionId, int userId, int bookId, TransactionType transactionType, std::string transactionDate);

    //copy constructor
    Transaction(const Transaction& other);

    //getter functions
    int getTransactionId() const;
    int getUserId() const;
    int getBookId() const;
    TransactionType getTransactionType() const;
    std::string getTransactionDate() const;

    //setter functions
    void setTransactionId(int transactionId);
    void setUserId(int userId);
    void setBookId(int bookId);
    void setTransactionType(TransactionType transactionType);
    void setTransactionDate(std::string date);

    //display transaction information
    void displayTransactionInfo();
};

#endif