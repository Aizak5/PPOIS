#include "Room.h"

Room::Room(int roomNumber, std::string building) : roomNumber(roomNumber), building(building) {}

int Room::getRoomNumber() const {
    return roomNumber;
}

std::string Room::getBuilding() const {
    return building;
}

