#pragma once

#include <vector>
#include <string>
#include "course.h"
#include "professor.h"
#include "student.h"

class Department {
public:
    Department(const std::string& name);

    void addCourse(Course* course);
    void addTeacher(Teacher* teacher);
    void addStudent(Student* student);

private:
    std::string name;
    std::vector<Course*> courses;   
    std::vector<Teacher*> teachers; 
    std::vector<Student*> students; 
};
