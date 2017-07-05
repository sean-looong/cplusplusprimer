/*
 * incr.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {

    int i = 0, j;

    j = ++i; // j = 1, i = 1
    cout << i << " " << j << endl;

    j = i++; // j = 1, i = 2
    cout << i << " " << j << endl;

    return 0;
}

