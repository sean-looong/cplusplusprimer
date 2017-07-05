/*
 * overflow.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cout;
using std::endl;

int main() {

    short short_value = 32767; // max value if shorts are 16 bits

    short_value += 1; // this calculation overflows
    cout << "short_value: " << short_value << endl;

    return 0;
}

