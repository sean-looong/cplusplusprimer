/*
 * add_using.cpp
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

#include <cctype>
using std::isupper;
using std::toupper;
using std::isspace;
using std::ispunct;

int main() {
    string s("Hello World!!!");
    // punct_cnt has the same type that s.size returns
    decltype(s.size()) punct_cnt = 0;

    // count the number of punctuation characters in s
    for (auto c: s) {
        if (ispunct(c)) {
            ++punct_cnt;
        }
    }

    cout << punct_cnt << " punctuation characters in " << s << endl;

    // convert s to uppercase
    string orig = s;
    for (auto &c: s) { // for every char in s (note: c is a reference)
        c = toupper(c);
    }
    
    cout << s << endl;

    // convert first word in s to uppercase
    s = orig;
    decltype(s.size()) index = 0;
    while (index != s.size() && !isspace(s[index])) {
        // s[index] returns a reference so we can change the underlying character
        s[index] = toupper(s[index]);
        ++index;
    }
    
    cout << s << endl;
    return 0;
}

