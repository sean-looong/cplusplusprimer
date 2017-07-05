/*
 * vec_init.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main() {

    vector<int> ivec;
    int cnt = 10;

    // add elements 10 ... 1
    while (cnt > 0) {
        ivec.push_back(cnt--);
    }

    // prints 10 9 8 ... 1
    auto iter = ivec.begin();
    while (iter != ivec.end()) {
        cout << *iter++ << " ";
    }
    cout << endl;

    vector<int> vec2(10, 0); // ten elements initially all 0
    cnt = vec2.size();
    for (vector<int>::size_type ix = 0;
         ix != vec2.size(); ++ix, --cnt) {
        vec2[ix] = cnt;
    }

    // prints 10 9 8 ... 1
    iter = vec2.begin();
    while (iter != vec2.end()) {
        cout << *iter++ << " ";
    }
    cout << endl;

    return 0;
}

