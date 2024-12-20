#pragma once

#include <string>
#include <vector>

class Student;
class Teacher;

class Course {
public:
    Course(int id, const std::string& name, int credits, Teacher* teacher);

    void addStudent(Student* student);
    void removeStudent(Student* student);
    void startCourse() const;
    void endCourse() const;
    const std::string& getName() const;

private:
    int id;
    std::string name;
    int credits;
    Teacher* teacher;  
    std::vector<Student*> students; 
};
