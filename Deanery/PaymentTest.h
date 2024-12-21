#ifndef PAYMENT_TEST_H
#define PAYMENT_TEST_H

#include "gtest/gtest.h"
#include "PaymentCard.h"
#include "Payment.h"
#include <memory>

class PaymentTest : public ::testing::Test {
protected:
    std::unique_ptr<PaymentCard> card;
    std::unique_ptr<Payment> payment;

    void SetUp() override {
        card = std::make_unique<PaymentCard>("1234-5678-9876-5432");
        payment = std::make_unique<Payment>(card.get(), 150.0);
    }
};

TEST_F(PaymentTest, MakePayment) {
    EXPECT_NO_THROW(payment->makePayment());
}

#endif // PAYMENT_TEST_H

