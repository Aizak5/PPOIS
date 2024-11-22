#include "Multiset.h"

Multiset::Multiset() = default;

Multiset::Multiset(const char& elem) {
    elements.insert(elem);
}

bool Multiset::isEmpty() const {
    return elements.empty();
}

void Multiset::add(const char elem) {
    elements.insert(elem);
}

void Multiset::remove(const char elem) {
    elements.erase(elem);
}

size_t Multiset::size() const {
    return elements.size();
}

bool Multiset::contains(const char elem) const {
    return elements.find(elem) != elements.end();
}

Multiset Multiset::operator+(const Multiset& other) const {
    Multiset result = *this;
    for (const auto& elem : other.elements) {
        result.add(elem);
    }
    return result;
}

void Multiset::operator+=(const Multiset& other) {
    for (const auto& elem : other.elements) {
        this->add(elem);
    }
}

Multiset Multiset::operator*(const Multiset& other) const {
    Multiset result;
    for (const auto& elem : elements) {
        if (other.contains(elem)) {
            result.add(elem);
        }
    }
    return result;
}

void Multiset::operator*=(const Multiset& other) {
    Multiset result;
    for (const auto& elem : elements) {
        if (other.contains(elem)) {
            result.add(elem);
        }
    }
    elements = result.elements;
}

Multiset Multiset::operator-(const Multiset& other) const {
    Multiset result;
    for (const auto& elem : elements) {
        if (!other.contains(elem)) {
            result.add(elem);
        }
    }
    return result;
}

void Multiset::operator-=(const Multiset& other) {
    Multiset result;
    for (const auto& elem : elements) {
        if (!other.contains(elem)) {
            result.add(elem);
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
            result.add(ch);  // Добавляем одиночный элемент
        }
    }
    return result;
}

Multiset Multiset::fromString(const char* str) {
    return fromString(std::string(str));  // Перегрузка для char* делает вызов для std::string
}

std::string Multiset::toString() const {
    std::stringstream ss;
    ss << "{ ";
    for (const auto& elem : elements) {
        ss << elem << " ";
    }
    ss << "}";
    return ss.str();
}

void Multiset::print() const {
    if (isEmpty()) {
        std::cout << "Empty ";
    } else {
        std::cout << "{ ";
        for (const auto& elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << "} ";
    }
}
