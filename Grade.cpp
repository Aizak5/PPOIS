#include "grade.h"
#include <iostream>

Grade::Grade(Student* student, Course* course, double grade)
    : student(student), course(course), grade(grade) {}

Student* Grade::getStudent() const {
    return student;
}

Course* Grade::getCourse() const {
    return course;
}

double Grade::getGrade() const {
    return grade;
}
