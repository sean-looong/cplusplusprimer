/*
 * ostreamIter.cpp
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

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

int main() {

    vector<int> vec;
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;

    while (in_iter != eof) {
        vec.push_back(*in_iter++);
    }

    ostream_iterator<int> out_iter(cout, " ");
    for (auto e: vec) {
        out_iter = e; // the assignment writes this element to cout
    }

    cout << endl;

    return 0;
}

