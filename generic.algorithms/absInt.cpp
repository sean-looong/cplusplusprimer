/*
 * absInt.cpp
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

#include <iterator>
using std::inserter;

#include <algorithm>
using std::for_each;
using std::transform;

int main() {

    vector<int> vi;
    int i;

    while (cin >> i) {
        vi.push_back(i);
    }
    // pass a lambda to for_earch to print each element in vi
    for_each(vi.begin(), vi.end(), [](int i){ cout << i << " "; });
    cout << endl;

    vector<int> orig = vi; // save original data in vi
    // replace negative values by their absolute value
    transform(vi.begin(), vi.end(),
        vi.begin(), [](int i) { return i < 0? -i: i; });
    for_each(vi.begin(), vi.end(), [](int i){ cout << i << " "; });
    cout << endl;

    vi = orig;
    // use a lambda with a specified return type to transform vi
    transform(vi.begin(), vi.end(),
        vi.begin(), [](int i) -> int { if (i < 0) return -i; return i; });
    for_each(vi.begin(), vi.end(), [](int i){ cout << i << " "; });
    cout << endl;

    return 0;
}

