#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "Teacher.h"

class Student;

class Course {
public:
    Course(const std::string& title, Teacher* teacher);

    std::string getTitle() const;
    Teacher* getTeacher() const;

    void addStudent(Student* student);
    std::vector<Student*> getStudents() const;

private:
    std::string title;  
    Teacher* teacher;  
    std::vector<Student*> students; 
};

#endif // COURSE_H

