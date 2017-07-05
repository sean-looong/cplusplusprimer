/*
 * unaryOps.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cout;
using std::endl;

int main() {

    int i = 1024;
    int k = -i;

    bool b = true;
    bool b2 = -b;

    cout << b << " " << b2 << endl;

    return 0;
}

