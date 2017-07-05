/*
 * arith-ex.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cout;
using std::endl;

int main() {

    cout << -30 * 3 + 21 / 5 << endl; // prints -86

    cout << -30 + 3 * 21 / 5 << endl; // prints -18

    cout << 30 / 3 * 21 % 5 << endl; // prints 0

    cout << 30 / 3 * 21 % 4 << endl; // prints 2

    cout << -30 / 3 * 21 % 4 << endl; // prints -2

    cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl; // prints 91

    return 0;
}

