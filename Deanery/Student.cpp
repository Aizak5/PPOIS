#include "student.h"
#include <iostream>
#include <algorithm>

Student::Student(int id, const std::string& lastName, const std::string& firstName,
    const std::string& dateOfBirth, const std::string& gender, const std::string& email)
    : id(id), lastName(lastName), firstName(firstName), dateOfBirth(dateOfBirth), gender(gender), email(email) {
    password = "default"; 
}

void Student::addCourse(Course* course) {
    courses.push_back(course);
    std::cout << "Student " << firstName << " enrolled in " << course->getName() << "\n";
}

void Student::removeCourse(Course* course) {
    courses.erase(std::remove(courses.begin(), courses.end(), course), courses.end());
    std::cout << "Student " << firstName << " dropped " << course->getName() << "\n";
}

void Student::enrollInCourse(Course* course) {
    addCourse(course);
}

void Student::dropCourse(Course* course) {
    removeCourse(course);
}

bool Student::checkPassword(const std::string& password) const {
    return this->password == password;
}

int Student::getId() const {
    return id;
}

std::string Student::getFullName() const {
    return firstName + " " + lastName;  
}
