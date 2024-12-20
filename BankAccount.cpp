#include "bankaccount.h"
#include <iostream>

BankAccount::BankAccount(int id, const std::string& owner, double initialBalance)
    : id(id), owner(owner), balance(initialBalance) {}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited " << amount << " to account. New balance: " << balance << "\n";
    }
    else {
        std::cout << "Invalid deposit amount.\n";
    }
}

void BankAccount::withdraw(double amount) {
    if (amount <= balance && amount > 0) {
        balance -= amount;
        std::cout << "Withdrew " << amount << " from account. New balance: " << balance << "\n";
    }
    else {
        std::cout << "Invalid withdrawal amount.\n";
    }
}

bool BankAccount::transfer(BankAccount& toAccount, double amount) {
    if (amount > 0 && amount <= balance) {
        this->withdraw(amount);
        toAccount.deposit(amount);
        std::cout << "Transferred " << amount << " from " << owner << " to " << toAccount.getOwner() << "\n";
        return true;
    }
    return false;
}

double BankAccount::getBalance() const {
    return balance;
}

const std::string& BankAccount::getOwner() const {
    return owner;
}
