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

    const string hexdigits = "0123456789ABCDEF"; // possible hex digits

    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished: "
         << endl;

    string result;
    string::size_type n; // hold numbers from the input
    while (cin >> n) {
        if (n < hexdigits.size()) {
            result += hexdigits[n];
        }
    }

    cout << "Your hex number is: " << result << endl;
    return 0;
}

