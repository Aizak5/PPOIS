#include "Grade.h"

Grade::Grade(Student* student, Course* course, double grade) 
    : student(student), course(course), grade(grade) {}

double Grade::getGrade() const {
    return grade;
}

Course* Grade::getCourse() const {
    return course;
}

Student* Grade::getStudent() const {
    return student;
}

