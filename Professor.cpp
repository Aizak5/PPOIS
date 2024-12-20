#include "Professor.h"
#include "course.h"
#include "student.h"
#include <iostream>

Teacher::Teacher(int id, const std::string& name, const std::string& position)
    : id(id), name(name), position(position) {}

void Teacher::assignCourse(Course* course) {
    courses.push_back(course);
}

void Teacher::gradeStudent(Student* student, const std::string& grade) {
    std::cout << "Professor " << name << " assigned grade " << grade << " to student " << student->getId() << "\n";
}

const std::string& Teacher::getName() const {
    return name;
}
