#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "student.h"
#include "course.h"
#include "grade.h"

class AcademicRecord {
public:
    AcademicRecord(Student* student);

    void addGrade(Course* course, double grade);

    double calculateGPA() const;


    Student* getStudent() const;

private:
    Student* student;  
    std::vector<Grade*> grades;  
};

