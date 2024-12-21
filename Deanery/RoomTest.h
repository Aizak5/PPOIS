#ifndef ROOM_TEST_H
#define ROOM_TEST_H

#include "gtest/gtest.h"
#include "Room.h"
#include <memory>

class RoomTest : public ::testing::Test {
protected:
    std::unique_ptr<Room> room;

    void SetUp() override {
         room = std::unique_ptr<Room>(new Room(101, "Building A"));

    }
};

TEST_F(RoomTest, GetRoomNumber) {
    EXPECT_EQ(room->getRoomNumber(), 101);
}

TEST_F(RoomTest, GetBuilding) {
    EXPECT_EQ(room->getBuilding(), "Building A");
}

#endif // ROOM_TEST_H

