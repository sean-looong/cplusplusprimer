/*
 * mainmath.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "LocalMath.h"

int main() {

    int f = fact(5); // f equals 120
    cout << "5! is " << f << endl;

    // call fact on i and print the result
    int i = 5;
    int j = fact(i);
    cout << i << "! is " << j << endl;

    // call fact on a const int
    const int ci = 3;
    int k = fact(ci);
    cout << ci << "! is " << k << endl;

    return 0;
}

