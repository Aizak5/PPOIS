#ifndef PAYMENT_H
#define PAYMENT_H

#include "PaymentCard.h"

class Payment {
public:
    Payment(PaymentCard* card, double amount);
    void makePayment();

private:
    PaymentCard* card;
    double amount;
};

#endif // PAYMENT_H

