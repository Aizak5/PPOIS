#include "Department.h"

Department::Department(std::string name) : name(name) {}

void Department::addCourse(Course* course) {
    courses.push_back(course);
}

void Department::addTeacher(Teacher* teacher) {
    teachers.push_back(teacher);
}

std::vector<Course*> Department::getCourses() const {
    return courses;
}

std::vector<Teacher*> Department::getTeachers() const {
    return teachers;
}

