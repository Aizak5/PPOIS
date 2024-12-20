#pragma once

#include <vector>
#include <string>

class Gradebook {
public:
    Gradebook(int studentId);

    void addGrade(const std::string& courseName, const std::string& grade);

private:
    int studentId;
    std::vector<std::pair<std::string, std::string>> grades;
};
