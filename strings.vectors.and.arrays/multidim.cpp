/*
 * multidim.cpp
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

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

int main() {

    // array of size 3; each element is an array of 4 uninitailzed ints
    int ia1[3][4];

    // array of size 10; each element is a 20-element array
    // whose elements are arrays of 30 ints
    int arr[10][20][30] = {0}; // initailze all elements to 0

    // assigns the first elements of arr to the last element
    // in the last raw of ia
    ia1[2][3] = arr[0][0][0];

    // binds row to the second four-element array in ia
    int (&raw)[4] = ia1[1];

    // three elements, each element is an array of size4
    int ia2[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
    };

    // equivalent inintialization without the optional
    // nested braces for each row
    int ia3[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    // explicitly initialize only element 0 in each row
    int ia4[3][4] = {{0}, {4}, {8}};
    // explicitly initilize row 0; the remaining elements
    // are vlue initialized
    int ix[3][4] = {0, 3, 6, 9};

    // prints 9 0 0
    cout << ix[0][3] << ' ' << ix[1][0] << ' ' << ix[2][0] << endl;

    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];

    for (size_t i = 0; i != rowCnt; ++i) {
        for (size_t j = 0; j != colCnt; ++j) {
            ia[i][j] = i * colCnt + j;
        }
    }

    // four ways to print the contents of ia
    // 1.
    for (const auto &row: ia) {
        for (auto col: row) {
            cout << col << ' ';
        }
    }
    cout << endl;
    cout << ia[0][0] << ' ' << ia[2][3] << endl; // prints 0 11

    // 2.
    for (auto p = ia; p != ia + rowCnt; ++p) {
        for (auto q = *p; q != *p + colCnt; ++q) {
            cout << *q << ' ';
        }
    }
    cout << endl;

    // 3.
    for (auto p = begin(ia); p != end(ia); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q) {
            cout << *q << ' ';
        }
    }
    cout << endl;

    // 4.
    using int_array = int[4];
    for (int_array *p = ia; p != ia + rowCnt; ++p) {
        for (auto q = *p; q != *p + colCnt; ++q) {
            cout << *q << ' ';
        }
    }
    cout << endl;

    int alt_ia[rowCnt][colCnt];
    size_t cnt = 0;
    for (auto &row: alt_ia) {
        for (auto &col: row) {
            col = cnt;
            ++cnt;
        }
    }

    for (const auto &row: alt_ia) {
        for (auto col: row) {
            cout << col << ' ';
        }
    }
    cout << endl;

    return 0;
}

