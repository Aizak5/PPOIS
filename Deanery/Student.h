#pragma once

#include <string>
#include <vector>
#include "course.h"
#include "transcript.h"

class Student {
public:
    Student(int id, const std::string& lastName, const std::string& firstName, const std::string& dateOfBirth,
        const std::string& gender, const std::string& email);

    void addCourse(Course* course);
    void removeCourse(Course* course);
    void enrollInCourse(Course* course);
    void dropCourse(Course* course);

    void viewTranscript() const;

    bool checkPassword(const std::string& password) const;

    int getId() const;
    std::string getFullName() const;  

private:
    int id;                    
    std::string lastName;      
    std::string firstName;     
    std::string dateOfBirth;   
    std::string gender;       
    std::string email;        
    std::string password;      
    std::vector<Course*> courses; 
    Transcript* transcript = nullptr;  
};

