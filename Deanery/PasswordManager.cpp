#include "passwordmanager.h"
#include <iostream>

PasswordManager::PasswordManager(const std::string& password)
    : password(password) {}

bool PasswordManager::checkPassword(const std::string& password) const {
    return this->password == password;
}

void PasswordManager::changePassword(const std::string& newPassword) {
    password = newPassword;
}
