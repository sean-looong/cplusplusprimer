/*
 * arrayScores.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <cstddef>

using std::size_t;

#include <vector>

using std::vector;

int main() {

    // hold the grades we read from the standard input
    vector<unsigned> grades;
    // count the number of grades by clusters of the:
    // 0---9, 10---19, ... 90---99, 100
    unsigned scores[11] = {}; // 11 buckets, all initially 0
    unsigned grade;
    
    while (cin >> grade) {
        if (grade <= 100) {
            grades.push_back(grade);
            ++scores[grade/10];
        }
    }

    cout << "grades.size = " << grades.size() << endl;
    for (auto it: grades) {
        cout << it << " ";
    }
    cout << endl;

    cout << "scores.size = " << sizeof(scores)/sizeof(unsigned) << endl;
    for (auto it: scores) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

