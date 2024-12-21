#include "Course.h"
#include "Student.h"

Course::Course(const std::string& title, Teacher* teacher)
    : title(title), teacher(teacher) {}

std::string Course::getTitle() const {
    return title;
}

Teacher* Course::getTeacher() const {
    return teacher;
}


void Course::addStudent(Student* student) {
    students.push_back(student);
}


std::vector<Student*> Course::getStudents() const {
    return students;
}

