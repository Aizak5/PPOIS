#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Grade.h"  

class Grade;

class Student {
public:
    Student(const std::string& fullName, int year);  

    std::string getFullName() const;
    int getYear() const;

private:
    std::string fullName;
    int year;
};

#endif // STUDENT_H

