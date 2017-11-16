/*
 * debug.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include "debug_rep.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

#ifndef DEBUG
#define DEBUG
#endif

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    string s("hi");
    cout << debug_rep(v) << endl;
    cout << debug_rep(s) << endl;
    cout << debug_rep("hi") << endl;
    cout << debug_rep(&v[0]) << endl;
    cout << debug_rep(&s) << endl;
    const string *sp = &s;
    cout << debug_rep(sp) << endl;

    char carr[] = "bye";
    cout << debug_rep(carr) << endl;
    vector<string> authors = {"Proust", "Shakespeare", "Barth"};
    vector<const char *> authors2 = {"Proust", "Shakespeare", "Barth"};
    cout << debug_rep(authors) << endl;
    cout << debug_rep(authors2) << endl;
    cout << debug_rep(s) << endl;
    s += "\\escape\"and quotes";
    cout << debug_rep(s) << endl;
    cout << debug_rep("hi world!") << endl;

    s = "hi";
    const char *cp = "bye";
    char arr[] = "world";
    cout << debug_rep(s) << endl;
    cout << debug_rep(cp) << endl;
    cout << debug_rep(arr) << endl;
    cout << debug_rep(&s) << endl;
    return 0;
}
