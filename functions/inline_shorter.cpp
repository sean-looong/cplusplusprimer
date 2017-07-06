/*
 * inline_shorter.cpp
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

inline const string& shorterString(const string& s1, const string& s2) {
    return s1.size() > s2.size()? s2: s1;
}

int main() {

    string s1("successes"), s2("failure");
    cout << shorterString(s1, s2) << endl;

    cout << shorterString(s1, s2).size() << endl;

    cout << (s1.size() > s2.size()? s2: s1) << endl;

    return 0;
}

