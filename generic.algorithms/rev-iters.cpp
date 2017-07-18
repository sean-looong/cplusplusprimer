/*
 * rev-iters.cpp
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


int main() {

    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto r_iter = vec.crbegin();
         r_iter != vec.crend();
         ++r_iter) {
        cout << *r_iter << " ";     
    }
    cout << endl;

    return 0;
}

