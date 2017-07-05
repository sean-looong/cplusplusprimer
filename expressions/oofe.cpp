/*
 * oofe.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstddef>
using std::tolower;
using std::toupper;

string &tolower(string &s) {
    for (auto &c: s) {
        c = tolower(c);
    }
    return s;
}

string &toupper(string &s) {
    for (auto &c: s) {
        c = toupper(c);
    }
    return s;
}

int main() {

    int i = 0;
    cout << i << " " << ++i << endl; // undefined 

    string s("a string"), orig = s;
    cout << toupper(s) << endl;
    cout << tolower(s) << endl;

    s = orig;

    cout << toupper(s) << " " << tolower(s) << endl; // undefined
    string first = toupper(s);
    string second = tolower(s);

    cout << first << " " << second << endl;
    cout << second << " " << first << endl;
    cout << first << " " << first << endl;
    cout << second << " " << second << endl;

    return 0;
}

