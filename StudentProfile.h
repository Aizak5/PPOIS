#pragma once

#include <string>

class StudentProfile {
public:
    StudentProfile(int studentId, const std::string& name, const std::string& email, const std::string& address);

    void updateProfile(const std::string& newName, const std::string& newEmail, const std::string& newAddress);

private:
    int studentId;
    std::string name;
    std::string email;
    std::string address;
};
