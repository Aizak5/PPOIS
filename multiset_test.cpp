#include <iostream>
#include "Multiset.h"

void testMultiset() {
    setlocale(LC_ALL,"rus");
    std::cout << "Test 1: Создать и добавить элементы из std::string\n";
    Multiset set1 = Multiset::fromString("{a, b, d}");
    set1.print();
    std::cout << "\n";

    std::cout << "Test 2: Создать и добавить элементы из char*\n";
    const char* str = "{d, e, f}";
    Multiset set2 = Multiset::fromString(str);
    set2.print();
    std::cout << "\n";

    std::cout << "Test 3: Объединение двух множеств\n";
    Multiset unionSet = set1 + set2;
    std::cout << "Объединение set1 и set2: ";
    unionSet.print();
    std::cout << "\n";

    std::cout << "Test 4: Пересечение двух множеств\n";
    Multiset intersectionSet = set1 * set2;
    std::cout << "Пересечение set1 и set2: ";
    intersectionSet.print();
    std::cout << "\n";

    std::cout << "Test 5: Разность двух множеств\n";
    Multiset differenceSet = set1 - set2;
    std::cout << "Разность set1 и set2: ";
    differenceSet.print();
    std::cout << "\n";
}

int main() {
    testMultiset();
    return 0;
}
