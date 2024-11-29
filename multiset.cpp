#include "multiset.h"
#include <iostream>
#include <sstream>
#include <map>
#include <string>

Multiset::Multiset() = default;

Multiset::Multiset(const char& elem) {
    elements[elem] = 1;  
}

bool Multiset::isEmpty() const {
    return elements.empty();
}

void Multiset::add(const char elem) {
    elements[elem]++;  
}

void Multiset::remove(const char elem) {
    auto it = elements.find(elem);
    if (it != elements.end()) {
        if (it->second > 1) {
            it->second--;  
        } else {
            elements.erase(it);  
        }
    }
}

size_t Multiset::size() const {
    size_t totalSize = 0;
    for (const auto& pair : elements) {
        totalSize += pair.second;  
    }
    return totalSize;
}

bool Multiset::contains(const char elem) const {
    return elements.find(elem) != elements.end();
}

Multiset Multiset::operator+(const Multiset& other) const {
    Multiset result = *this;
    for (const auto& elem : other.elements) {
        result.elements[elem.first] += elem.second; 
    }
    return result;
}

void Multiset::operator+=(const Multiset& other) {
    for (const auto& elem : other.elements) {
        elements[elem.first] += elem.second;  
    }
}

Multiset Multiset::operator*(const Multiset& other) const {
    Multiset result;
    for (const auto& elem : elements) {
        auto it = other.elements.find(elem.first);
        if (it != other.elements.end()) {
            result.elements[elem.first] = std::min(elem.second, it->second);  
        }
    }
    return result;
}

void Multiset::operator*=(const Multiset& other) {
    Multiset result;
    for (const auto& elem : elements) {
        auto it = other.elements.find(elem.first);
        if (it != other.elements.end()) {
            result.elements[elem.first] = std::min(elem.second, it->second);  
        }
    }
    elements = result.elements;
}

Multiset Multiset::operator-(const Multiset& other) const {
    Multiset result;
    for (const auto& elem : elements) {
        auto it = other.elements.find(elem.first);
        if (it == other.elements.end() || it->second < elem.second) {
            result.elements[elem.first] = elem.second - (it != other.elements.end() ? it->second : 0);
        }
    }
    return result;
}

void Multiset::operator-=(const Multiset& other) {
    Multiset result;
    for (const auto& elem : elements) {
        auto it = other.elements.find(elem.first);
        if (it == other.elements.end() || it->second < elem.second) {
            result.elements[elem.first] = elem.second - (it != other.elements.end() ? it->second : 0);
        }
    }
    elements = result.elements;
}

Multiset Multiset::fromString(const std::string& str) {
    Multiset result;
    std::stringstream ss(str);
    char ch;
    while (ss >> ch) {
        if (ch != ',' && ch != ' ' && ch != '{' && ch != '}') {
            result.add(ch);  
        }
    }
    return result;
}

Multiset Multiset::fromString(const char* str) {
    return fromString(std::string(str));
}

std::string Multiset::toString() const {
    std::stringstream ss;
    ss << "{ ";
    for (const auto& elem : elements) {
        for (size_t i = 0; i < elem.second; ++i) {
            ss << elem.first << " ";  
        }
    }
    ss << "}";
    return ss.str();
}

void Multiset::print() const {
    if (isEmpty()) {
        std::cout << "Empty ";
    }
    else {
        std::cout << "{ ";
        for (const auto& elem : elements) {
            for (size_t i = 0; i < elem.second; ++i) {
                std::cout << elem.first << " ";  
            }
        }
        std::cout << "} ";
    }
}
