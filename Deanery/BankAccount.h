#pragma once

#include <string>

class BankAccount {
public:
    BankAccount(int id, const std::string& owner, double initialBalance);

    void deposit(double amount);
    void withdraw(double amount);
    bool transfer(BankAccount& toAccount, double amount);
    double getBalance() const;
    const std::string& getOwner() const;

private:
    int id;
    std::string owner;
    double balance;
};

