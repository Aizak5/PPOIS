#include <iostream>
#include "Multiset.h"

void testMultiset() {
    std::cout << "Test 1: Creating and adding elements\n";
    Multiset set1 = Multiset::fromString("{a, b, c}");
    set1.print();
    std::cout << "\n";

    std::cout << "Test 2: Adding more elements\n";
    set1.add('d');
    set1.print();
    std::cout << "\n";

    std::cout << "Test 3: Checking the size\n";
    std::cout << "Size of set1: " << set1.size() << "\n";

    std::cout << "Test 4: Removing an element\n";
    set1.remove('b');
    set1.print();
    std::cout << "\n";

    std::cout << "Test 5: Checking if an element exists\n";
    std::cout << "Contains 'c': " << (set1.contains('c') ? "Yes" : "No") << "\n";

    std::cout << "Test 6: Union of two sets\n";
    Multiset set2 = Multiset::fromString("{c, d, e}");
    Multiset unionSet = set1 + set2;
    std::cout << "Union of set1 and set2: ";
    unionSet.print();
    std::cout << "\n";

    std::cout << "Test 7: Intersection of two sets\n";
    Multiset intersectionSet = set1 * set2;
    std::cout << "Intersection of set1 and set2: ";
    intersectionSet.print();
    std::cout << "\n";

    std::cout << "Test 8: Difference of two sets\n";
    Multiset differenceSet = set1 - set2;
    std::cout << "Difference of set1 and set2: ";
    differenceSet.print();
    std::cout << "\n";
}

int main() {
    testMultiset();
    return 0;
}
