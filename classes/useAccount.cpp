/*
 * useAccount.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Account.h"

int main() {
    Account a1("bem", 42);
    cout << a1.balance() << endl;
    a1.calculate();
    cout << a1.balance() << endl;

    return 0;
}

