#include "Transcript.h"

Transcript::Transcript(Student* student) : student(student) {}

void Transcript::addGrade(Grade* grade) {
    grades.push_back(grade);
}

std::vector<Grade*> Transcript::getGrades() const {
    return grades;
}

Student* Transcript::getStudent() const {
    return student;
}

double Transcript::calculateGPA() const {
    double totalGrades = 0.0;
    for (const Grade* grade : grades) {
        totalGrades += grade->getGrade();
    }
    return grades.empty() ? 0.0 : totalGrades / grades.size();
}

