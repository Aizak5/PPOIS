#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>
#include "Course.h"
#include "Room.h"

class Schedule {
public:
    Schedule(Course* course, Room* room, std::string time);
    Course* getCourse() const;
    Room* getRoom() const;
    std::string getTime() const;

private:
    Course* course;
    Room* room;
    std::string time;
};

#endif // SCHEDULE_H

