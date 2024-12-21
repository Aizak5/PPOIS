#ifndef DEAN_TEST_H
#define DEAN_TEST_H

#include "gtest/gtest.h"
#include "Dean.h"

TEST(DeanTest, CreateDean) {
    Dean dean("Dr. Sarah Black");
    EXPECT_EQ(dean.getFullName(), "Dr. Sarah Black");
}

#endif // DEAN_TEST_H

