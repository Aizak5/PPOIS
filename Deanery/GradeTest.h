#ifndef GRADE_TEST_H
#define GRADE_TEST_H

#include "gtest/gtest.h"
#include "Grade.h"
#include "Student.h"
#include "Course.h"
#include "Teacher.h"

TEST(GradeTest, CreateGrade) {
    Student student("Alice Smith", 2);
    Teacher teacher("Dr. Brown", 2);
    Course course("Physics 101", &teacher);
    Grade grade(&student, &course, 90.0);
 
    EXPECT_EQ(grade.getStudent(), &student);
    EXPECT_EQ(grade.getCourse(), &course);
    EXPECT_DOUBLE_EQ(grade.getGrade(), 90.0);
}

#endif // GRADE_TEST_H

