/*
 * directcall.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cout; using std::endl; using std::ostream;
#include <string>
using std::string;
#include "Sales_data.h"

int main(void) {
    Sales_data data1, data2;
    std::cin >> data1 >> data2;
    cout << data1 + data2 << endl;
    cout << 42 + 5 << endl;

    data1 + data2;
    operator+(data1, data2);
    cout << operator+(data1, data2) << endl;

    data1 += data2;
    data1.operator+=(data2);
    cout << data1 << endl;
    return 0;
}

