#include "Dean.h"
#include <iostream>

Dean::Dean(std::string fullName) : fullName(fullName) {}

void Dean::approveStudentForCourse(Student* student, Course* course) {
    std::cout << "Dean " << fullName << " approved student " << student->getFullName() 
              << " for course " << course->getTitle() << ".\n";
}

void Dean::issueCertificate(Student* student) {
    std::cout << "Dean " << fullName << " issued certificate to " << student->getFullName() << ".\n";
}

