#include "gradebook.h"
#include <iostream>

Gradebook::Gradebook(int studentId)
    : studentId(studentId) {}

void Gradebook::addGrade(const std::string& courseName, const std::string& grade) {
    grades.push_back({ courseName, grade });
}
