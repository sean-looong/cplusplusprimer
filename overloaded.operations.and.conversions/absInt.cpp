/*
 * absInt.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <iterator>
using std::inserter;
#include <algorithm>
using std::transform;

struct absInt {
    int operator()(int val) {
        return val < 0? -val: val;
    }
};

int main(void) {
    int i = -42;
    absInt absObj;
    unsigned ui = absObj(i); // passes i to absObj.operator
    cout << i << " " << ui << endl;

    vector<int> vi;
    while (cin >> i) {
        vi.push_back(i);
    }

    vector<int> vu;
    transform(vi.begin(), vi.end(), back_inserter(vu), absObj);

    for_each(vu.begin(), vu.end(), [](int i) {cout << i << " ";});
    cout << endl;

    vector<int> vu2;
    transform(vi.begin(), vi.end(), back_inserter(vu2),
            [](int i) {return i < 0? -i: i;});
    if (vu == vu2) {
        cout << "as expected" << endl;
    } else {
        cout << "something is wrong, vectors differ" << endl;
        for_each(vu2.begin(), vu2.end(), [](int i) {cout << i << " ";});
        cout << endl;
    }

    return 0;
}

