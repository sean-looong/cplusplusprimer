/*
 * array-parms4.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

// when we call print the compiler will instantiate a version of print
// with T replaced by the argument's element type, and N by that array's dimension
template <typename T, size_t N>
void print(T (&arr)[N]) {
    for (auto elem: arr) {
        cout << elem << endl; 
    }
}

int main(void) {
    int a1[] = {0, 1 ,2, 3, 4, 5, 6, 7, 8, 9};
    int a2[] = {1, 3, 5};
    string a3[4];

    print(a1); // instantiates print(int (&arr)[10])
    print(a2); // instantiates print(int (&arr)[3])
    print(a3); // instantiates print(string (&arr)[4]);
    return 0;
}

