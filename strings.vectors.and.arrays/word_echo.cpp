/*
 * word_echo.cpp
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

    string word;
    while (cin >> word) {
        cout << word << endl;
    }

    return 0;
}

