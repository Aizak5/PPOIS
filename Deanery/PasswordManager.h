#pragma once

#include <string>

class PasswordManager {
public:
    PasswordManager(const std::string& password);

    bool checkPassword(const std::string& password) const;
    void changePassword(const std::string& newPassword);

private:
    std::string password;
};

