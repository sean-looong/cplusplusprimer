/*
 * rangefor.cpp
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

int main() {

    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto &r: v) {
        r *= 2;
    }

    for (const auto r: v) {
        cout << r << " ";
    }
    
    cout << endl;

    return 0;
}

