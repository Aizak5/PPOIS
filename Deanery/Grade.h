#pragma once

#include <string>
#include "student.h"
#include "course.h"

class Grade {
public:
    // Изменяем конструктор, чтобы он принимал Student*, Course* и оценку типа double
    Grade(Student* student, Course* course, double grade);
    Student* getStudent() const;
    Course* getCourse() const;
    double getGrade() const;

private:
    Student* student;  
    Course* course;    
    double grade;      
};

