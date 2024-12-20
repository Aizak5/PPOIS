#pragma once

#include <vector>
#include <string>
#include "student.h"
#include "professor.h"
#include "course.h"

class University {
public:
    University(const std::string& name);

    void addStudent(Student* student);
    void addTeacher(Teacher* teacher);
    void addCourse(Course* course);
    void enrollStudentInCourse(Student* student, Course* course);

private:
    std::string name;
    std::vector<Student*> students;    
    std::vector<Teacher*> teachers;    
    std::vector<Course*> courses;    
};
