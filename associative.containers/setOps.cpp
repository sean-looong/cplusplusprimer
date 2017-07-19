/*
 * setOps.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <map>
using std::map;

#include <utility>
using std::pair;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <set>
using std::set;
using std::multiset;

int main() {

    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i); // duplicate copies of each number
    }

    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());

    cout << ivec.size() << endl;  // prints 20
    cout << iset.size() << endl;  // prints 10
    cout << miset.size() << endl; // prints 20

    iset.find(1);
    iset.find(11); // returns the iterator == iset.end();
    miset.count(1);  // returns 2
    miset.count(11); // returns 0

    set<string> set1;
    set1.insert("the");
    set1.insert("and");

    ivec = {2, 3, 6, 8, 2, 3, 6, 8};
    set<int> set2;
    set2.insert(ivec.cbegin(), ivec.cend());  // set2 has four elements
    set2.insert({1, 3, 5, 7, 1, 3, 5, 7,}); // set2 has eight elements

    return 0;
}

