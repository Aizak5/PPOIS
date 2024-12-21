#include "PaymentCard.h"
#include <iostream>

PaymentCard::PaymentCard(std::string cardNumber) : cardNumber(cardNumber) {}

bool PaymentCard::validateCard(std::string cardNumber) {
    return this->cardNumber == cardNumber;
}

void PaymentCard::transferFunds(double amount) {
    std::cout << "Transferring " << amount << " from card " << cardNumber << ".\n";
}

