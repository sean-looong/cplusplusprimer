/*
 * vecSubs.cpp
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

    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto sz = v.size();
    decltype(sz) i = 0;
    // duplicate contents of v onto the back of v
    while (i != sz) {
        v.push_back(*v.begin() + i);
        ++i;
    }
    // prints 0...9 0...9
    for (auto it: v) {
        cout << it << " ";
    }
    cout << endl;

    vector<int> alt_v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (decltype(alt_v.size()) i = 0, sz = alt_v.size(); i != sz; ++i) {
        alt_v.push_back(alt_v[i]);
    }
    // prints 0...9 0...9
    for (auto it: v) {
        cout << it << " ";
    }
    cout << endl;

    vector<int> v2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    decltype(v2.size()) ix = 0;
    // set the elements with values less than 5 to 0
    while (ix != v2.size() && ix < 5) {
        v2[ix] = 0;
        ++ix;
    }
    for (decltype(v2.size()) i = 0; i < v2.size(); ++i) {
        cout << v2[i] << " ";
    }
    cout << endl;

    vector<int> alt_v2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // set the elements to 0 up to the first one that is 5 or greater
    auto it = alt_v2.begin();
    while (it != alt_v2.end() && *it < 5) {
        *it = 0;
        ++it;
    }
    for (auto it = alt_v2.cbegin(); it != alt_v2.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

