/*
 * vecStrings2.cpp
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

#include <vector>

using std::vector;

int main() {

    vector<string> text; // holds the input

    string s;
    while (getline(cin, s)) {
        text.push_back(s);
    }

    cout << "text.size: " << text.size() << endl;

    for (auto it = text.cbegin(); it != text.cend(); ++it) {
        cout << *it << endl;
    }

    return 0;
}

