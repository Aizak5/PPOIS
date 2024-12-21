#ifndef DEAN_OFFICE_TEST_H
#define DEAN_OFFICE_TEST_H

#include "gtest/gtest.h"
#include "DeanOffice.h"
#include "Dean.h"
#include "Student.h"

TEST(DeanOfficeTest, AddStudentToDeanOffice) {
    Dean dean("Dr. Sarah Black");
    DeanOffice deanOffice(&dean);

    Student student1("Jack White", 1);
    Student student2("Olivia Brown", 2);

    deanOffice.addStudent(&student1);
    deanOffice.addStudent(&student2);

    EXPECT_EQ(deanOffice.getStudents().size(), 2);
    EXPECT_EQ(deanOffice.getStudents()[0], &student1);
    EXPECT_EQ(deanOffice.getStudents()[1], &student2);
}

#endif // DEAN_OFFICE_TEST_H

