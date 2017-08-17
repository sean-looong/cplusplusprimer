/*
 * substr.c
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <string>
#include <iostream>

using std::cout; using std::endl;
using std::string;

string::size_type position(const string &a,
        const string &b, const string &c) {
    return (a + b).find(c);
}

int main() {
    string s1 = "a value", s2 = "another";
    auto x = position(s1, s2, "val");

    if (x == string::npos) {
        cout << "not found" << endl;
    } else if (x < s1.size()) {
        cout << "value is in first parameter" << endl;
    } else {
        cout << "value is in second parameter" << endl;
    }

    auto n = (s1 + s2).find('a');
    cout << "n = " << n << endl;
    s1 + s2 = "wow!";
    return 0;
}
