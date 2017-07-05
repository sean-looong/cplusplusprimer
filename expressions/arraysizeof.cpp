/*
 * arraysizeof.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cout;
using std::endl;

#include <cstddef>
using std::size_t;

int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };

int main() {

    constexpr size_t sz = sizeof(ia) / sizeof(int);

    int arr2[sz]; // ok sizeof returns a constant expression

    cout << "ia size " << sz << endl;

    return 0;
}

