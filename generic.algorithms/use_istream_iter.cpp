/*
 * use_istream_iter.cpp
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

#include <list>
using std::list;

#include <string>
using std::string;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <algorithm>
using std::find;

int main() {

    vector<int> vec;
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;

    while (in_iter != eof) {
        vec.push_back(*in_iter++);
    }
    
    ostream_iterator<int> out_iter(cout, " ");
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    for (auto e: vec) {
        *out_iter++ = e;
    }
    cout << endl;

    return 0;
}

