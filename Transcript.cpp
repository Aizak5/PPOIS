#include "transcript.h"
#include "course.h"
#include <iostream>

Transcript::Transcript(int studentId)
    : studentId(studentId) {}

void Transcript::addCourseGrade(Course* course, const std::string& grade) {
    coursesAndGrades.push_back({ course, grade });
}


