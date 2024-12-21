#ifndef TEACHER_H
#define TEACHER_H

#include <string>

class Teacher {
public:
    Teacher(std::string fullName, int id);
    std::string getFullName() const;
    int getId() const;

private:
    std::string fullName;
    int id;
};

#endif // TEACHER_H

