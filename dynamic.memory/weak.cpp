/*
 * weak.cpp
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
using std::make_shared; using std::shared_ptr; using std::weak_ptr;

int main() {

    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);

    p.reset();

    if (shared_ptr<int> np = wp.lock()) {
        cout << "np is not null" << endl;
    } else {
        cout << "np is null" << endl;
    }

    return 0;
}

