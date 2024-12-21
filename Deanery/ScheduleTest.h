#pragma once
#include "gtest/gtest.h"
#include "Schedule.h"
#include "Room.h"
#include "Course.h"  

class CourseTest : public ::testing::Test {
protected:
    Course* course;
    Room* room;
    Schedule* schedule;

    void SetUp() override {
        course = new Course("Mathematics");
        room = new Room(101, "Building A");
        schedule = new Schedule(course, room, "9:00 AM");
    }

    void TearDown() override {
        delete schedule;
        delete room;
        delete course;
    }
};

TEST_F(CourseTest, GetCourse) {
    EXPECT_EQ(schedule->getCourse()->getName(), "Mathematics");
}

TEST_F(CourseTest, GetRoom) {
    EXPECT_EQ(schedule->getRoom()->getRoomNumber(), 101);
    EXPECT_EQ(schedule->getRoom()->getBuilding(), "Building A");
}

TEST_F(CourseTest, GetTime) {
    EXPECT_EQ(schedule->getTime(), "9:00 AM");
}

