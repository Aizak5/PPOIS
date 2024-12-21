#include "Schedule.h"

Schedule::Schedule(Course* course, Room* room, std::string time)
    : course(course), room(room), time(time) {}

Course* Schedule::getCourse() const {
    return course;
}

Room* Schedule::getRoom() const {
    return room;
}

std::string Schedule::getTime() const {
    return time;
}

