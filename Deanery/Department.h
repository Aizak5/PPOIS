#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include "Course.h"
#include "Teacher.h"

class Department {
public:
    Department(std::string name);
    void addCourse(Course* course);
    void addTeacher(Teacher* teacher);
    std::vector<Course*> getCourses() const;
    std::vector<Teacher*> getTeachers() const;

private:
    std::string name;
    std::vector<Course*> courses;
    std::vector<Teacher*> teachers;
};

#endif // DEPARTMENT_H

