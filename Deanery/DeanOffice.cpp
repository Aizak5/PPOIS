#include "DeanOffice.h"
#include <iostream>

DeanOffice::DeanOffice(Dean* dean) : dean(dean) {}

void DeanOffice::openOffice() {
    std::cout << "The dean's office of " << dean->getFullName() << " is now open.\n";
}

