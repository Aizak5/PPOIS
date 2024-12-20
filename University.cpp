#include "university.h"
#include <iostream>

University::University(const std::string& name)
    : name(name) {}

void University::addStudent(Student* student) {
    students.push_back(student);
    std::cout << "Student " << student->getId() << " added to the university.\n";
}

void University::addTeacher(Teacher* teacher) {
    teachers.push_back(teacher);
    std::cout << "Professor " << teacher->getName() << " added to the university.\n";
}

void University::addCourse(Course* course) {
    courses.push_back(course);
    std::cout << "Course " << course->getName() << " added to the university.\n";
}

void University::enrollStudentInCourse(Student* student, Course* course) {
    student->addCourse(course);
    course->addStudent(student);
    std::cout << "Student " << student->getId() << " enrolled in course " << course->getName() << ".\n";
}
