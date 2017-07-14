/*
 * substr.cpp
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

#include <stdexcept>
using std::out_of_range;

int main() {

    try {
        string s("hello world");
        cout << s.substr(0, 5) << endl; // prints hello
        cout << s.substr(6) << endl; // prints world 
        cout << s.substr(6, 11) << endl; // prints world 
        cout << s.substr(12) << endl; // throws out_of_range
    } catch (out_of_range) {
        cout << "caught out_of_range";
    }

    return 0;
}

