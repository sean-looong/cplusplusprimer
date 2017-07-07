/*
 * stl-arr-fcns.cpp
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

void print(const char *cp) {
    if (cp) { // if cp is not a null pointer
        while (*cp) { // so long as the charactor it points to is not a null character
            cout << *cp++;
        }
    }
}

void print(const int *begin, const int *end) {
    while (begin != end) {
        cout << *begin++ << " ";
    }
}

int main() {

    print("hi world!"); // calls first version of print
    cout << endl;

    int j[2] {0, 1};
    print(begin(j), end(j));
    cout << endl;

    // equivalent call. dirctly calculate the begin and end pointers
    print(j, j + 2);
    cout << endl;
    return 0;
}

