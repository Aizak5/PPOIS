#include "Exam.h"

Exam::Exam(Course* course, Student* student, std::string date) 
    : course(course), student(student), date(date), grade(0.0) {}

void Exam::setGrade(double grade) {
    this->grade = grade;
}

double Exam::getGrade() const {
    return grade;
}

std::string Exam::getDate() const {
    return date;
}

Course* Exam::getCourse() const {
    return course;
}

Student* Exam::getStudent() const {
    return student;
}
