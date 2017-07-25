/*
 * unique.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>

using std::string; using std::vector;
using std::ifstream;
using std::shared_ptr;
using std::cout; using std::cin; using std::endl;

int main() {

    shared_ptr<string> p(new string("Hello!"));
    shared_ptr<string> p2(p);

    string newVal("World!");
    if (!p.unique()) {
        p.reset(new string(*p));
    }

    *p += newVal;

    cout << *p << " " << *p2 << endl;

    return 0;
}

