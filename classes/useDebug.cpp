/*
 * useDebug.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cerr;
using std::endl;

#include "Debug.h"

int main() {
    constexpr Debug io_sub(false, true, false); // debugging IO
    if (io_sub.any()) {
        cerr << "print appropriate error messages" << endl;
    }

    constexpr Debug prod(false); // no debugging duyring production
    if (prod.any()) {
        cerr << "print an error messages" << endl;
    }

    IO_Subsystem ioErrs; // by default, don't print any debuging
    if (ioErrs.default_debug()) {
        cerr << "print message 3" << endl;
    }
    ioErrs.set_debug(true);
    if (ioErrs.default_debug()) {
        cerr << "print message 4" << endl;
    }
    ioErrs.set_debug(false);

    HW_Subsystem hwErrs;
    hwErrs.set_debug(true);
    if (ioErrs.default_debug() || hwErrs.default_debug()) {
        cerr << "print message 5" << endl;
    }

    return 0;
}

