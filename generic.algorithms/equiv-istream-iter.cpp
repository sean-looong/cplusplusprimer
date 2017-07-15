/*
 * equal.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iterator>
using std::istream_iterator;

#include <vector>
using std::vector;

int main() {

    // use istream_iterator to initialize a vector
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);

    for (auto it: vec) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

