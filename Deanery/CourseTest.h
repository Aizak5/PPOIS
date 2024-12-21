#ifndef COURSE_TEST_H
#define COURSE_TEST_H

#include "gtest/gtest.h"
#include "Course.h"
#include "Teacher.h"

TEST(CourseTest, CreateCourse) {
    Teacher teacher("Dr. Smith", 1);
    Course course("Math 101", &teacher);
    EXPECT_EQ(course.getTeacher()->getFullName(), "Dr. Smith");
    EXPECT_EQ(course.getTitle(), "Math 101");
}

TEST(CourseTest, AssociateCourseWithTeacher) {
    Teacher teacher("Dr. John Smith", 1);
    Course course("Physics 101", &teacher);
    EXPECT_EQ(course.getTeacher()->getFullName(), "Dr. John Smith");
}

#endif // COURSE_TEST_H

