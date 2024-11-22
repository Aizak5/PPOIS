#include <iostream>
#include "Multiset.h"

void testMultiset() {
    std::cout << "Test 1: Creating and adding elements from std::string\n";
    Multiset set1 = Multiset::fromString("{a, b, d}");
    set1.print();
    std::cout << "\n";

    std::cout << "Test 2: Creating and adding elements from char*\n";
    const char* str = "{d, e, f}";
    Multiset set2 = Multiset::fromString(str);
    set2.print();
    std::cout << "\n";

    std::cout << "Test 3: Union of two sets\n";
    Multiset unionSet = set1 + set2;
    std::cout << "Union of set1 and set2: ";
    unionSet.print();
    std::cout << "\n";

    std::cout << "Test 4: Intersection of two sets\n";
    Multiset intersectionSet = set1 * set2;
    std::cout << "Intersection of set1 and set2: ";
    intersectionSet.print();
    std::cout << "\n";

    std::cout << "Test 5: Difference of two sets\n";
    Multiset differenceSet = set1 - set2;
    std::cout << "Difference of set1 and set2: ";
    differenceSet.print();
    std::cout << "\n";
}

int main() {
    testMultiset();
    return 0;
}
