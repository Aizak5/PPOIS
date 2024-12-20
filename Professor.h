#pragma once

#include <string>
#include <vector>

class Course;
class Student;

class Teacher {
public:
    Teacher(int id, const std::string& name, const std::string& position);

    void assignCourse(Course* course);
    void gradeStudent(Student* student, const std::string& grade);
    const std::string& getName() const;

private:
    int id;
    std::string name;
    std::string position;
    std::vector<Course*> courses;
};
