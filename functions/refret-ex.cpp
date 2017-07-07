/*
 * refret-ex.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int &get(int *array, int index) {
    return array[index];
}

int main() {


    int ia[10];

    for (int i = 0; i != 10; ++i) {
        get(ia, i) = i;
    }

    for (const auto i: ia) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}

