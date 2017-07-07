/*
 * wdebug.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <cstddef>
using std::size_t;

#include <cassert>
#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cerr;
using std::endl;

void print(const int ia[], size_t size) {
#ifndef NDEBUG
    cerr << __func__ << ": array size if " << size << endl;
#endif
}

int main() {

    string word = "foo";
    const string::size_type threshold = 5;

    if (word.size() < threshold) {
        cerr << "Error: " << __FILE__
             << " : in function " << __func__
             << " at line " << __LINE__ << endl
             << "       Compiled on " << __DATE__
             << " at " << __TIME__ << endl
             << "       Word read was \"" << word
             << "\": Length too short" << endl;
    }
    word = "something longer than five chars";
    assert(word.size() > threshold);

    return 0;
}

