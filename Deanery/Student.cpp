#include "Student.h"

Student::Student(const std::string& fullName, int year)  
    : fullName(fullName), year(year) {}

std::string Student::getFullName() const {  
    return fullName;
}

int Student::getYear() const {  
    return year;
}

