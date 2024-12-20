#pragma once
#include <string>
#include <vector>

class Course;

class Transcript {
public:
    Transcript(int studentId);

    void addCourseGrade(Course* course, const std::string& grade);

private:
    int studentId;
    std::vector<std::pair<Course*, std::string>> coursesAndGrades; 
};
