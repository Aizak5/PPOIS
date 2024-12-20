#include "academic_record.h"
#include <algorithm>

AcademicRecord::AcademicRecord(Student* student) : student(student) {}

void AcademicRecord::addGrade(Course* course, double grade) {
    Grade* gradeObj = new Grade(student, course, grade);  
    grades.push_back(gradeObj);
    std::cout << "Grade " << grade << " for " << student->getFullName() << " in course " << course->getName() << " has been added.\n";
}

double AcademicRecord::calculateGPA() const {
    if (grades.empty()) return 0.0;

    double totalGrades = 0.0;
    for (const Grade* grade : grades) {
        totalGrades += grade->getGrade();
    }

    return totalGrades / grades.size();
}

Student* AcademicRecord::getStudent() const {
    return student;
}
