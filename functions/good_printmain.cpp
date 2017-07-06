/*
 * good_printmain.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iterator>
using std::begin;
using std::end;

#include <cstddef>
using std::size_t;

void print(const int ia[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << ia[i] << " ";
    }
    cout << endl;
}

int main() {

    int j[] = {0, 1};
    print(j, end(j) - begin(j));
    return 0;
}

