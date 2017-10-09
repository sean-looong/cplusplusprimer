/*
 * compare.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cstring>
using std::strcmp;
#include <iostream>
using std::cout; using std::endl;

#include "compare.h"

int main() {
    cout << compare(1, 0) << endl; // T is int

    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl; // T is vector<int>

    long l1, l2;
    int i1, i2;

    compare(i1, i2); // instantiate compare(int, int)
    compare(l1, l2); // instantiate compare(long, long)
    compare<int>(i1, l2); // use compare(int, int)
    compare<long>(i1, l2); // use compare(long, long)

    const char *cp1 = "hi", *cp2 = "world";
    compare(cp1, cp2); // calls the specialization
    compare<string>(cp1, cp2); // converts arguments to string

    return 0;
}

