/*
 * string_size3.cpp
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

int main() {

    string line;

    // read input a line at a time and discard blank lines
    while (getline(cin, line)) {
        if (!line.empty()) {
            cout << line << endl;
        }
    }

    return 0;
}

