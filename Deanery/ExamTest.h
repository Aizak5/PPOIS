#ifndef EXAM_TEST_H
#define EXAM_TEST_H

#include "gtest/gtest.h"
#include "Exam.h"
#include "Student.h"
#include "Course.h"
#include "Teacher.h"

TEST(ExamTest, ExamGradeAssignment) {
    Student student("David Green", 4);
    Teacher teacher("Dr. Gray", 5);
    Course course("History 101", &teacher);
    Exam exam(&course, &student, "2024-05-15");

    exam.setGrade(95.0);
    EXPECT_DOUBLE_EQ(exam.getGrade(), 95.0);
    EXPECT_EQ(exam.getDate(), "2024-05-15");
    EXPECT_EQ(exam.getCourse(), &course);
    EXPECT_EQ(exam.getStudent(), &student);
}

#endif // EXAM_TEST_H

