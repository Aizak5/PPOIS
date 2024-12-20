#pragma once

#include <vector>
#include <string>
#include "course.h"
#include "professor.h"

class Schedule {
public:
    void assignCourseToTeacher(Course* course, Teacher* teacher, const std::string& scheduleTime);

private:
    struct ScheduleEntry {
        Course* course;
        Teacher* teacher;
        std::string scheduleTime;
    };

    std::vector<ScheduleEntry> schedule;
};

