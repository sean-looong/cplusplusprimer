/*
 * ref-fcn.cpp
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

char &get_val(string &str, string::size_type ix) {
    return str[ix];
}

int main() {

    string s("a value");
    cout << s << endl;

    get_val(s, 0) = 'A';
    cout << s << endl;

    return 0;
}

