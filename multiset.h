#pragma once
#ifndef MULTISET_H
#define MULTISET_H

#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <memory>

class Multiset {
private:
    std::set<char> elements; // Множество элементов типа char

public:
    // Конструкторы
    Multiset();
    Multiset(const char& elem);

    // Методы
    bool isEmpty() const;
    void add(const char elem);
    void remove(const char elem);
    size_t size() const;
    bool contains(const char elem) const;

    // Операторы
    Multiset operator+(const Multiset& other) const;
    void operator+=(const Multiset& other);
    Multiset operator*(const Multiset& other) const;
    void operator*=(const Multiset& other);
    Multiset operator-(const Multiset& other) const;
    void operator-=(const Multiset& other);

    // Методы для строк
    static Multiset fromString(const std::string& str);
    std::string toString() const;

    // Метод вывода множества
    void print() const;

};

#endif // MULTISET_H
