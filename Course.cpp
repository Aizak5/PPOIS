#include "course.h"
#include "student.h"
#include "professor.h"
#include <iostream>

Course::Course(int id, const std::string& name, int credits, Teacher* teacher)
    : id(id), name(name), credits(credits), teacher(teacher) {}

void Course::addStudent(Student* student) {
    students.push_back(student);
}

void Course::removeStudent(Student* student) {
    students.erase(std::remove(students.begin(), students.end(), student), students.end());
}

void Course::startCourse() const {
    std::cout << "Course " << name << " started by " << teacher->getName() << "\n";
}

void Course::endCourse() const {
    std::cout << "Course " << name << " ended.\n";
}

const std::string& Course::getName() const {
    return name;
}
