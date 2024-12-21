#ifndef DEAN_H
#define DEAN_H

#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"

class Dean {
public:
    Dean(const std::string& fullName)
        : fullName(fullName) {}

    std::string getFullName() const { return fullName; }  

private:
    std::string fullName; 
};

#endif // DEAN_H

