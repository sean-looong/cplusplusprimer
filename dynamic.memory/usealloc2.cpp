/*
 * usealloc2.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>

using std::string; using std::vector;
using std::ifstream;
using std::allocator;
using std::uninitialized_fill_n; using std::uninitialized_copy;
using std::cout; using std::cin; using std::endl;

int main() {

    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    allocator<int> alloc;

    auto p = alloc.allocate(vi.size() * 2);
    auto q = uninitialized_copy(vi.begin(), vi.end(), p);
    uninitialized_fill_n(q, vi.size(), 42);

    for (size_t i = 0; i != vi.size(); ++i) {
        cout << *(p + i) << " ";
    }
    cout << endl;

    for (size_t i = 0; i != vi.size(); ++i) {
        cout << *(q + i) << " ";
    }
    cout << endl;

    alloc.deallocate(p, vi.size() * 2);

    return 0;
}

