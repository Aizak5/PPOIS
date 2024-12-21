#ifndef STUDENT_TEST_H
#define STUDENT_TEST_H

#include "gtest/gtest.h"
#include "Student.h"

TEST(StudentTest, CreateStudent) {
    Student student(std::string("John Doe"), 1);
    EXPECT_EQ(student.getFullName(), "John Doe");
    EXPECT_EQ(student.getYear(), 1);
}

#endif // STUDENT_TEST_H

