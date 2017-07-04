/*
 * add_using.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main() {

    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i: v) {
        i *= i;
    }

    for (auto i: v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

