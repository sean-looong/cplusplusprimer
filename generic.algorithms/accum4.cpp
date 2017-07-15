/*
 * accum4.cpp
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

#include <numeric>
using std::accumulate;

int main() {

    istream_iterator<int> in(cin), eof;    
    cout << accumulate(in, eof, 0) << endl;

    return 0;
}

