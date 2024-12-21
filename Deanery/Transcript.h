#ifndef TRANSCRIPT_H
#define TRANSCRIPT_H

#include <string>
#include <vector>
#include "Grade.h"
#include "Course.h"

class Transcript {
public:
    Transcript(Student* student);
    void addGrade(Grade* grade);
    std::vector<Grade*> getGrades() const;
    Student* getStudent() const;
    double calculateGPA() const;

private:
    Student* student;
    std::vector<Grade*> grades;
};

#endif // TRANSCRIPT_H

