/*
 * reset.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

void reset(int &i) {
    i = 0;
}

void reset(int *i) {
    *i = 0;
}

int main() {

    int j = 42;
    reset(j);
    cout << "j = " << j << endl;

    j = 42;
    reset(&j);
    cout << "j = " << j << endl;

    j = 42;
    int *p  = &j;
    reset(&j);
    cout << "j = " << *p << endl;

    return 0;
}

