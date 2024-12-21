#ifndef TEACHER_TEST_H
#define TEACHER_TEST_H

#include "gtest/gtest.h"
#include "Teacher.h"

TEST(TeacherTest, CreateTeacher) {
    Teacher teacher("Dr. John Smith", 1);
    EXPECT_EQ(teacher.getFullName(), "Dr. John Smith");
}

#endif // TEACHER_TEST_H

