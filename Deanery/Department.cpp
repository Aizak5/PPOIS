#include "department.h"
#include <iostream>

Department::Department(const std::string& name)
    : name(name) {}

void Department::addCourse(Course* course) {
    courses.push_back(course);
}

void Department::addTeacher(Teacher* teacher) {
    teachers.push_back(teacher);
}

void Department::addStudent(Student* student) {
    students.push_back(student);
}
