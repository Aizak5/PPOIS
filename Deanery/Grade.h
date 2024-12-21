#ifndef GRADE_H
#define GRADE_H

#include "Course.h"
#include "Student.h"  

class Grade {
public:
    Grade(Student* student, Course* course, double grade)
        : student(student), course(course), grade(grade) {}

    Grade() : student(nullptr), course(nullptr), grade(0.0) {}

    Student* getStudent() const { return student; }
    Course* getCourse() const { return course; }
    double getGrade() const { return grade; }

private:
    Student* student;
    Course* course;
    double grade;
};

#endif // GRADE_H

