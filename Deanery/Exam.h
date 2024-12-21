#ifndef EXAM_H
#define EXAM_H

#include <string>
#include "Course.h"
#include "Student.h"

class Exam {
public:
    Exam(Course* course, Student* student, std::string date);
    void setGrade(double grade);
    double getGrade() const;
    std::string getDate() const;
    Course* getCourse() const;
    Student* getStudent() const;

private:
    Course* course;
    Student* student;
    std::string date;
    double grade;
};

#endif // EXAM_H

