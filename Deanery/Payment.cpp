#include "Payment.h"

Payment::Payment(PaymentCard* card, double amount) : card(card), amount(amount) {}

void Payment::makePayment() {
    card->transferFunds(amount);
}

