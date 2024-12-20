#include "studentprofile.h"
#include <iostream>

StudentProfile::StudentProfile(int studentId, const std::string& name, const std::string& email, const std::string& address)
    : studentId(studentId), name(name), email(email), address(address) {}

void StudentProfile::updateProfile(const std::string& newName, const std::string& newEmail, const std::string& newAddress) {
    name = newName;
    email = newEmail;
    address = newAddress;
    std::cout << "Profile updated.\n";
}
