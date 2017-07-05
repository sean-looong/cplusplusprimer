/*
 * cond.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

vector<unsigned> grades;

int main() {

    unsigned i;

    while (cin >> i) {
        grades.push_back(i);
    }

    for (auto grade: grades) {
        string finalgrade = (grade > 90)? "high pass": (grade < 60)? "fail": "pass";
        cout << grade << " " << finalgrade << endl;
    }

    return 0;
}

