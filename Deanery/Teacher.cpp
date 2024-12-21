#include "Teacher.h"

Teacher::Teacher(const std::string fullName, int id) : fullName(fullName), id(id) {}

std::string Teacher::getFullName() const {
    return fullName;
}

int Teacher::getId() const {
    return id;
}


