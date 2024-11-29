#pragma once
#include <gtest/gtest.h>
#include "multiset.h"
#include <sstream>

TEST(MultisetTest, DefaultConstructor) {
    Multiset ms;
    EXPECT_TRUE(ms.isEmpty());
    EXPECT_EQ(ms.size(), 0);
}

TEST(MultisetTest, AddElement) {
    Multiset ms;
    ms.add('a');
    EXPECT_EQ(ms.size(), 1);
    EXPECT_TRUE(ms.contains('a'));
}

TEST(MultisetTest, AddDuplicateElement) {
    Multiset ms;
    ms.add('a');
    ms.add('a');
    EXPECT_EQ(ms.size(), 2);
}

TEST(MultisetTest, RemoveElement) {
    Multiset ms;
    ms.add('a');
    ms.remove('a');
    EXPECT_EQ(ms.size(), 0);
    EXPECT_FALSE(ms.contains('a'));
}

TEST(MultisetTest, RemoveElementWithMultipleOccurrences) {
    Multiset ms;
    ms.add('a');
    ms.add('a');
    ms.remove('a');
    EXPECT_EQ(ms.size(), 1);
    ms.remove('a');
    EXPECT_EQ(ms.size(), 0);
}

TEST(MultisetTest, UnionOperator) {
    Multiset ms1, ms2;
    ms1.add('a');
    ms1.add('b');
    ms2.add('b');
    ms2.add('c');
    
    Multiset result = ms1 + ms2;
    EXPECT_EQ(result.size(), 4);
    EXPECT_TRUE(result.contains('a'));
    EXPECT_TRUE(result.contains('b'));
    EXPECT_TRUE(result.contains('c'));
}

TEST(MultisetTest, MinusEqualOperatorWithSmallerElements) {
    Multiset set1;
    Multiset set2;

    set1.add('a');
    set1.add('b');
    
    set2.add('a');
    set2.add('b');
    set2.add('b');

    set1 -= set2;
    
    EXPECT_EQ(set1.size(), 0);
    EXPECT_FALSE(set1.contains('a'));
    EXPECT_FALSE(set1.contains('b'));
}

TEST(MultisetTest, MultiplyEqualOperatorWithNoCommonElements) {
    Multiset set1;
    Multiset set2;

    set1.add('a');
    set1.add('b');
    set1.add('b');
    
    set2.add('c');
    set2.add('d');

    set1 *= set2;
    
    EXPECT_EQ(set1.size(), 0);
    EXPECT_FALSE(set1.contains('a'));
    EXPECT_FALSE(set1.contains('b'));
    EXPECT_FALSE(set1.contains('c'));
    EXPECT_FALSE(set1.contains('d'));
}

TEST(MultisetTest, IntersectionOperator) {
    Multiset ms1, ms2;
    ms1.add('a');
    ms1.add('b');
    ms2.add('b');
    ms2.add('c');
    
    Multiset result = ms1 * ms2;
    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(result.contains('b'));
}

TEST(MultisetTest, DifferenceOperator) {
    Multiset ms1, ms2;
    ms1.add('a');
    ms1.add('b');
    ms2.add('b');
    ms2.add('c');
    
    Multiset result = ms1 - ms2;
    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(result.contains('a'));
}

TEST(MultisetTest, AddAndAssignOperator) {
    Multiset ms1, ms2;
    ms1.add('a');
    ms1.add('b');
    ms2.add('c');
    ms2.add('d');
    
    ms1 += ms2;
    EXPECT_EQ(ms1.size(), 4);
    EXPECT_TRUE(ms1.contains('a'));
    EXPECT_TRUE(ms1.contains('b'));
    EXPECT_TRUE(ms1.contains('c'));
    EXPECT_TRUE(ms1.contains('d'));
}

TEST(MultisetTest, FromString) {
    Multiset ms = Multiset::fromString("{a, b, b, c}");
    EXPECT_EQ(ms.size(), 4);
    EXPECT_TRUE(ms.contains('a'));
    EXPECT_TRUE(ms.contains('b'));
    EXPECT_TRUE(ms.contains('c'));
}

TEST(MultisetTest, ToString) {
    Multiset ms;
    ms.add('a');
    ms.add('b');
    ms.add('b');
    
    EXPECT_EQ(ms.toString(), "{ a b b }");
}

TEST(MultisetTest, Print) {
    Multiset ms;
    ms.add('a');
    ms.add('b');
    
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    ms.print();
    
    std::cout.rdbuf(old);
    
    EXPECT_EQ(buffer.str(), "{ a b } ");
}

TEST(MultisetTest, EmptyMultiset) {
    Multiset ms;
    EXPECT_TRUE(ms.isEmpty());
    EXPECT_EQ(ms.size(), 0);
}

TEST(MultisetTest, SingleElementMultiset) {
    Multiset ms;
    ms.add('x');
    EXPECT_EQ(ms.size(), 1);
    ms.remove('x');
    EXPECT_TRUE(ms.isEmpty());
}

TEST(MultisetTest, LargeMultiset) {
    Multiset ms;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        ms.add(ch);
    }
    EXPECT_EQ(ms.size(), 26);
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        EXPECT_TRUE(ms.contains(ch));
    }
}
