#include "schedule.h"
#include <iostream>

void Schedule::assignCourseToTeacher(Course* course, Teacher* teacher, const std::string& scheduleTime) {
    ScheduleEntry entry = { course, teacher, scheduleTime };
    schedule.push_back(entry);
    std::cout << "Course " << course->getName() << " assigned to teacher " << teacher->getName()
        << " at " << scheduleTime << "\n";
}


