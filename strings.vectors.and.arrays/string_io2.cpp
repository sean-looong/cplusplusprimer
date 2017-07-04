/*
 * string_io.cpp
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

    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << s2 << endl;

    return 0;
}

