/*
 * Array.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <vector>
using std::vector;
#include <list>
using std::list;
#include <initializer_list>
using std::initializer_list;
#include <string>
using std::string;
#include <cstring>
using std::strcmp;
#include <iostream>
using std::cout; using std::endl;
#include <iterator>
using std::begin; using std::end;

#include "Blob.h"

int main() {
    Blob<int> ia;
    Blob<int> ia2 = {0, 1, 2, 3, 4};
    vector<int> v1(10, 0);
    Blob<int> ia3(v1.begin(), v1.end());
    cout << ia << "\n" << ia2 << "\n" << ia3 << endl;

    Blob<string> names;
    Blob<double> prices;

    Blob<string> articles = {"a", "an", "the"};
    Blob<int> squares = {0,1,2,3,4,5,6,7,8,9};
    cout << squares << endl;
    for (size_t i = 0; i != squares.size(); ++i) {
        squares[i] = i * i;
    }
    cout << squares << endl;

    vector<long> vl = {0,1,2,3,4,5,6,7,8,9};
    Blob<int> a1(vl.begin(), vl.end());

    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    Blob<int> a2(begin(arr), end(arr));

    list<int> li(10, 0);
    Blob<int> zeros(li.begin(), li.end());

    cout << a1 << "\n" << zeros << endl;

    a1.swap(zeros);
    cout << a1 << "\n" << zeros << endl;

    list<const char*> w = {"now", "is", "the", "time"};

    Blob<string> a3(w.begin(), w.end());

    return 0;
}

