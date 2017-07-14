/*
 * refreshIter.cpp
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

void printVec(const vector<int> &vi) {
    auto iter = vi.begin();
    while (iter != vi.end()) {
        cout << *iter++ << " ";
    }
    cout << endl;
}

int main() {

    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printVec(vi);

    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter); // duplicate it
            iter += 2;
        } else {
            iter = vi.erase(iter);
        }
    }

    printVec(vi);

    return 0;
}

