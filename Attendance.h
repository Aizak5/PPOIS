#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "student.h"
#include "course.h"

class Attendance {
public:
    Attendance(Course* course);

    void markAttendance(Student* student, const std::string& date, bool attended);
    bool hasStudentAttendedOnDate(Student* student, const std::string& date) const;

private:
    Course* course;
    std::unordered_map<Student*, std::unordered_map<std::string, bool>> attendanceRecords;
};