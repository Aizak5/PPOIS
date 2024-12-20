#include "materials.h"
#include <iostream>

void Materials::addMaterial(Course* course, const std::string& material) {
    materials.push_back({ course, material });
    std::cout << "Material added for course " << course->getName() << ": " << material << "\n";
}

void Materials::listMaterials(Course* course) const {
    std::cout << "Materials for course " << course->getName() << ":\n";
    for (const auto& material : materials) {
        if (material.course == course) {
            std::cout << "- " << material.material << "\n";
        }
    }
}
