/*
 * sortSI.cpp
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

#include <algorithm>
using std::sort;

#include "Sales_item.h"

int main() {
    Sales_item trans;
    vector<Sales_item> file;

    while (cin >> trans) {
        file.push_back(trans);
    }

    for (auto i: file) {
        cout << i << endl;
    }
    cout << '\n' << endl;

    sort(file.begin(), file.end(), compareIsbn);
    for (auto i: file) {
        cout << i << endl;
    }
    cout << '\n' << endl;
    return 0;
}

