#include "attendance.h"
#include <iostream>
#include <unordered_map>

Attendance::Attendance(Course* course) : course(course) {}

void Attendance::markAttendance(Student* student, const std::string& date, bool attended) {
    attendanceRecords[student][date] = attended;
    std::cout << "Attendance for " << student->getId() << " in course " << course->getName()
        << " on " << date << " marked as " << (attended ? "Present" : "Absent") << ".\n";
}


bool Attendance::hasStudentAttendedOnDate(Student* student, const std::string& date) const {
    auto studentIt = attendanceRecords.find(student);
    if (studentIt != attendanceRecords.end()) {
        auto dateIt = studentIt->second.find(date);
        if (dateIt != studentIt->second.end()) {
            return dateIt->second;
        }
    }
    return false;  
}
