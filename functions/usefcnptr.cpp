/*
 * usefcnptr.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int min_element(vector<int>::iterator, vector<int>::iterator);

int (*pf)(vector<int>::iterator, vector<int>::iterator) = min_element;

int main() {

    vector<int> ivec{4, 5, 6, 1, 7, 8};

    cout << "Direct call: "
         << min_element(ivec.begin(), ivec.end()) << endl;

    cout << "Indirect call: "
         << pf(ivec.begin(), ivec.end()) << endl;

    cout << "equivalent indirect call: "
         << (*pf)(ivec.begin(), ivec.end()) << endl;

    return 0;
}

// returns minimum element in an vector of ints
int min_element(vector<int>::iterator begin,
                vector<int>::iterator end) {
    int minVal = *begin;                
    while (begin != end) {
        if (*begin < minVal) {
            minVal = *begin;
        }
        ++begin;
    }

    return minVal;
}

