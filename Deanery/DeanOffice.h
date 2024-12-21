#ifndef DEANOFFICE_H
#define DEANOFFICE_H

#include "Dean.h"

class DeanOffice {
public:
    DeanOffice(Dean* dean) : dean(dean) {}

    void addStudent(Student* student) {
        students.push_back(student);
    }

    const std::vector<Student*>& getStudents() const {
        return students;
    }

private:
    Dean* dean;
    std::vector<Student*> students;
};

#endif // DEANOFFICE_H

