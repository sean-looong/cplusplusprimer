/*
 * make_plural.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "make_plural.h"

int main() {
    size_t cnt = 1;
    cout << make_plural(cnt, "success", "es") << endl;

    cnt = 2;
    cout << make_plural(cnt, "success", "es") << endl;

    return 0;
}

