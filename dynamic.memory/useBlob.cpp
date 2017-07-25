/*
 * useBlob.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include "StrBlob.h"

using std::cout; using std::cin; using std::endl;

int main() {
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }

    cout << b1.size() << endl;
    for (auto it = b1.begin(); neq(it, b1.end()); it.incr()) {
        cout << it.deref() << endl;
    }

    return 0;
}

