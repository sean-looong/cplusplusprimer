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

#include <cstddef>
using std::size_t;

int arr[10];
int *p1[10]; // p1 is an array of ten pointers
int (*p2)[10] = &arr; // p2 points to an array of ten ints

using arrT = int[10]; // arrT is a synonym for the type array of ten ints

// three ways to declare function returning pointer to array of ten ints
arrT *func(int i);
auto func(int i) -> int(*)[10];
int (*func(int i))[10]; // direct declaration

auto func2(int i) -> int(&)[10]; // func2 returns a refernce to an array

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

// returns a pointer to an int in one of these arrays
int *elemPtr(int i) {
    return (i % 2)? odd: even;
}

// returns a pointer to an array of five int elements
decltype(odd) *arrPtr(int i) {
    return (i % 2)? &odd: &even;
}

// returns a reference to an array of five int elements
int (&arrRef(int i))[5] {
    return (i % 2)? odd: even;
}

int main() {

    int *p = elemPtr(6); // p points to an int
    int (*arrP)[5] = arrPtr(5); // arrP points to an array of five ints
    int (&arrR)[5] = arrRef(4); // arrP refers to an array of five ints

    for (size_t i = 0; i < 5; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < 5; ++i) {
        cout << (*arrP)[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < 5; ++i) {
        cout << arrR[i] << " ";
    }
    cout << endl;

    return 0;
}

