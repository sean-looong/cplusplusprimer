/*
 * rcomma.cpp
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

#include <algorithm>
using std::for_each;
using std::transform;

int main() {

    string line;
    getline(cin, line);

    // find the first element in a comma-separated list
    auto comma = find(line.cbegin(), line.cend(), ',');
    cout << string(line.cbegin(), comma) << endl;

    // find the last element in a comma-separated list
    auto rcomma = find(line.crbegin(), line.crend(), ',');
    // WRONG: will generate the word in reverse order
    cout << string(line.crbegin(), rcomma) << endl;
    // ok: get a forward iterator and read to the end of line
    cout << string(rcomma.base(), line.cend()) << endl;

    return 0;
}

