/*
 * reverse.cpp
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
using std::back_inserter;

#include <algorithm>
using std::for_each;
using std::reverse;
using std::reverse_copy;

int main() {

    vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2;
    vector<int> v3 = v1;

    find(v1.begin(), v1.end(), 42); // find first element equal to 42
    find_if(v1.begin(), v1.end(),
        [](int i) { return i % 2; }); // find first odd element
    // puts elements in v1 into reverse order
    reverse(v1.begin(), v1.end());
    v1 = v3;

    // copies elements from v1 into v2 in reverse order; v1 is unchanged
    reverse_copy(v1.begin(), v1.end(), back_inserter(v2));
    for (auto i: v1) {
        cout << i << " ";
    }
    cout << endl;

    for (auto i: v2) {
        cout << i << " ";
    }
    cout << endl;

    // removes the odd elements from v1
    auto it = remove_if(v1.begin(), v1.end(),
        [](int i) { return i % 2; });
    for_each(v1.begin(), v1.end(), [](int i){ cout << i << " "; });
    cout << endl;

    v1 = v3;
    v2.clear();

    remove_copy_if(v1.begin(), v1.end(), back_inserter(v2), 
        [](int i) { return i % 2; });
    for (auto i: v2) {
        cout << i << " ";
    }
    cout << endl;

    for (auto i: v1) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

