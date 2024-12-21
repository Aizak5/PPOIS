#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
public:
    Room(int roomNumber, std::string building);
    int getRoomNumber() const;
    std::string getBuilding() const;

private:
    int roomNumber;
    std::string building;
};

#endif // ROOM_H

