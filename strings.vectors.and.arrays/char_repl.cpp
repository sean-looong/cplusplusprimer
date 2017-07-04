/*
 * char_repl.cpp
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
using std::toupper;
using std::isspace;

int main() {

    string str("some string"), orig = str;

    if (!str.empty()) {
        cout << str[0] << endl; // print the first character in str
    }

    if (!str.empty()) {
        str[0] = toupper(str[0]);
    }
    cout << str << endl;

    str = orig;

    // equivalent code using iterators instead of subscript
    if (str.begin() != str.end()) {
        auto it = str.begin();
        *it = toupper(*it);
    }
    cout << str << endl;

    // for ways to capitalize first word in str
    // 1. for loop with subscripts
    str = orig;
    for (decltype(str.size()) index = 0;
         index != str.size() && !isspace(str[index]);
         ++index) {
        str[index] = toupper(str[index]);
    }
    cout << str << endl;
    // 2.for loop with iterators instead of subscripts
    str = orig;
    for (auto it = str.begin();
         it != str.end() && !isspace(*it);
         ++it) {
        *it = toupper(*it);
    }
    cout << str << endl;
    // 3. while instead of a for with subscripts
    str = orig;
    decltype(str.size()) index = 0;
    while (index != str.size() && !isspace(str[index])) {
        str[index] = toupper(str[index]);
        ++index;
    }
    cout << str << endl;
    // 4. while loop with iterators
    str = orig;
    auto it = str.begin();
    while (it != str.end() && !isspace(*it)) {
        *it = toupper(*it);
        ++it;
    }
    cout << str << endl;

    str = orig;
    // range for loop to process every character
    // first a loop to print the characters in str one character to a line
    for (auto c: str) {
        cout << c << endl;
    }

    // next change every character in str
    for (auto &c: str) {
        c = '*';
    }
    cout << str << endl;
    
    str = orig;
    // equivalent code using traditional for loops
    for (decltype(str.size()) ix = 0; ix != str.size(); ++ix) {
        cout << str[ix] << endl;
    }

    for (decltype(str.size()) ix = 0; ix != str.size(); ++ix) {
        str[ix] = '*';
    }
    cout << str << endl;

    str = orig;

    for (auto beg = str.begin(); beg != str.end(); ++beg) {
        cout << *beg << endl;
    }

    for (auto beg = str.begin(); beg != str.end(); ++beg) {
        *beg = '*';
    }
    cout << str << endl;
    return 0;
}

