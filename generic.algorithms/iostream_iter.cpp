/*
 * iostream_iter.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;

#include <algorithm>
using std::copy;
using std::sort;
using std::unique_copy;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

int main() {

    istream_iterator<int> int_it(cin);
    istream_iterator<int> int_eof;
    vector<int> v(int_it, int_eof);

    sort(v.begin(), v.end());
    ostream_iterator<int> out(cout, " ");
    unique_copy(v.begin(), v.end(), out);
    cout << endl;
    ofstream out_file("data/outFile2");
    ostream_iterator<int> out_iter(out_file, " ");
    copy(v.begin(), v.end(), out_iter);
    out_file << endl;

    return 0;
}

