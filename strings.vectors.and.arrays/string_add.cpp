/*
 * string_add.cpp
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

    string s1 = "hello, ", s2 = "world\n";
    string s3 = s1 + s2; // s3 is hello, world\n

    cout << s1 << s2 << s3 << endl;

    s1 += s2;
    cout << s1;

    string s4 = "hello", s5 = "world";
    string s6 = s4 + ", " + s5 + "\n";
    cout << s4 << s5 << "\n" << s6 << endl;

    return 0;
}

