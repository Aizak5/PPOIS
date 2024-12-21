#ifndef TRANSCRIPT_TEST_H
#define TRANSCRIPT_TEST_H

#include "gtest/gtest.h"
#include "Transcript.h"
#include "Student.h"
#include "Grade.h"
#include "Course.h"
#include "Teacher.h"

TEST(TranscriptTest, AddGradeToTranscript) {
    Student student("Bob Johnson", 3);
    Teacher teacher("Dr. White", 3);
    Course course("Chemistry 101", &teacher);
    Grade grade(&student, &course, 88.0);

    Transcript transcript(&student);
    transcript.addGrade(&grade);

    EXPECT_EQ(transcript.getGrades().size(), 1);
    EXPECT_EQ(transcript.getGrades()[0], &grade);
}

TEST(TranscriptTest, CalculateGPA) {
    Student student("Emily Davis", 2);
    Teacher teacher("Dr. Black", 4);
    Course course1("Biology 101", &teacher);
    Course course2("Math 101", &teacher);
    Grade grade1(&student, &course1, 85.0);
    Grade grade2(&student, &course2, 90.0);

    Transcript transcript(&student);
    transcript.addGrade(&grade1);
    transcript.addGrade(&grade2);

    EXPECT_DOUBLE_EQ(transcript.calculateGPA(), 87.5);
}

#endif // TRANSCRIPT_TEST_H

