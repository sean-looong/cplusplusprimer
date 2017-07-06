/*
 * fact.cpp
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

    cout << factorial(5) << endl;
    cout << fact(5) << endl;
    cout << factorial(0) << endl;
    cout << fact(0) << endl;

    return 0;
}

