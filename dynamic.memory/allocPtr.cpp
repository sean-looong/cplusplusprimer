/*
 * allocPtr.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

#include "Foo.h"

using std::cout; using std::cin; using std::endl;

Foo* factory(T arg) {
    return new Foo(arg);
}

Foo* use_factory(T arg) {
    Foo *p = factory(arg);
    print(cout, *p);
    cout << endl;
    return p;
}

int main() {
    T arg;
    while (cin >> arg) {
        auto p = use_factory(arg);
        delete p;
    }

    return 0;
}

