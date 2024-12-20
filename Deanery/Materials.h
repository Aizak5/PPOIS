#pragma once

#include <vector>
#include <string>
#include "course.h"

class Materials {
public:
    void addMaterial(Course* course, const std::string& material);
    void listMaterials(Course* course) const;

private:
    struct Material {
        Course* course;
        std::string material;
    };

    std::vector<Material> materials;
};
