#ifndef PAYMENTCARD_H
#define PAYMENTCARD_H

#include <string>

class PaymentCard {
public:
    PaymentCard(std::string cardNumber);
    bool validateCard(std::string cardNumber);
    void transferFunds(double amount);

private:
    std::string cardNumber;
};

#endif // PAYMENTCARD_H

