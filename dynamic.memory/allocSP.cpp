/*
 * allocSP.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include <vector>
#include <memory>

#include "Foo.h"

using std::cout; using std::cin; using std::endl; using std::vector;
using std::make_shared; using std::shared_ptr;

shared_ptr<Foo> factory(T arg) {
    return make_shared<Foo>(arg);
}

shared_ptr<Foo> use_factory(T arg) {
    shared_ptr<Foo> p = factory(arg);
    print(cout, *p);
    cout << endl;
    return p;
}

int main() {
    T arg;
    while (cin >> arg) {
        auto p = use_factory(arg);
    }

    return 0;
}

