#pragma once

#include <string>
#include "student.h"
#include "course.h"

class Grade {
public:
    // �������� �����������, ����� �� �������� Student*, Course* � ������ ���� double
    Grade(Student* student, Course* course, double grade);
    Student* getStudent() const;
    Course* getCourse() const;
    double getGrade() const;

private:
    Student* student;  
    Course* course;    
    double grade;      
};

