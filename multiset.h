#ifndef MULTISET_H
#define MULTISET_H

#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <memory>

class Multiset {
private:
    std::set<char> elements; 

public:
    Multiset();
    Multiset(const char& elem);

    bool isEmpty() const;
    void add(const char elem);
    void remove(const char elem);
    size_t size() const;
    bool contains(const char elem) const;
    
    Multiset operator+(const Multiset& other) const;
    void operator+=(const Multiset& other);
    Multiset operator*(const Multiset& other) const;
    void operator*=(const Multiset& other);
    Multiset operator-(const Multiset& other) const;
    void operator-=(const Multiset& other);

    static Multiset fromString(const std::string& str);
    static Multiset fromString(const char* str); 
    std::string toString() const;

    void print() const;

};

#endif 
