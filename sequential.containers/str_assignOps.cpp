/*
 * str_assignOps.cpp
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

    string s = "some string", s2 = "some other string";
    // equivalent ways to insert all the characters from s2 at beginning of s
    // insert iterator range begore s.begin()
    s.insert(s.begin(), s2.begin(), s2.end());
    cout << "insert iterators version:        " << s << endl;

    s = "some string";
    s.insert(0, s2); // insert a copy of s2 before position 0 in s
    cout << "insert string at given position: " << s << endl;

    s = "some string";
    // insert s2.size() characters from s2 starting at s2[0] before s[0]
    s.insert(0, s2, 0, s2.size());
    cout << "insert position version:         " << s << endl;

    s = ""; // s is now empty
    vector<char> c_vec(1, 'a');
    // insert characters from c_vec into a
    s.insert(s.begin(), c_vec.begin(), c_vec.end());
    s.insert(s.size(), 5, '!'); // add five exclamation points at the end of s
    cout << s << endl;

    s.erase(s.size() - 5, 5); // erase the last five characters from s
    cout << s << endl;

    s = "";
    const char *cp = "Stately, plump Buck";
    s.assign(cp, 7); // s == "Stately"
    cout << s << endl;
    s.insert(s.size(), cp + 7); // s == "Stately, plump Buck"
    cout << s << endl;

    s = "C++ Primer";
    s2 = s;
    s.insert(s.size(), " 4th Ed."); // s == "C++ Primer 4th Ed";
    s2.append(" 4th Ed."); // equivalent: appends "4th Ed." to s2;
    cout << s << " " << s2 << endl;

    // two ways to replace "4th" by "5th"
    s.erase(11, 3); // s = "C++ Primer  Ed"
    s.insert(11, "5th"); // s = "C++ Primer 5th Ed"
    s2.replace(11, 3, "5th");
    cout << s << " " << s2 << endl;
    
    // two way to replace "5th" by "Fifth"
    s.replace(11, 3, "Fifth");

    auto pos = s2.find("5th");
    if (pos != string::npos) {
        s2.replace(pos, 3, "Fifth");
    } else {
        cout << "something's wrong, s2 is: " << s2 << endl;
    }
    cout << s << " " << s2 << endl;

    return 0;
}

