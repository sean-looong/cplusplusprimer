/*
 * count-calls.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstddef>
using std::size_t;

size_t count_calls() {
    static size_t cnt = 0;
    return ++cnt;
}

int main() {

    for (size_t i = 0; i != 10; ++i) {
        cout << count_calls() << endl;
    }

    return 0;
}

