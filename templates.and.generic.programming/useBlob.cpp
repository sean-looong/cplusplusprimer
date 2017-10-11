/*
 * useBlob.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;

#include "Blob.h"

int main() {
    Blob<string> b1;
    cout << b1.size() << endl;
    {
        Blob<string> b2 = {"a", "an", "the"};
        b1 = b2; // b1 and b2 share the same elements
        b2.push_back("about");
        cout << b1.size() << " " << b2.size() << endl;
    }
    cout << b1.size() << endl;

    for (auto p = b1.begin(); p != b1.end(); ++p) {
        cout << *p << endl;
    }

    return 0;
}

