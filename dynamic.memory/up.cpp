/*
 * up.cpp
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
using std::unique_ptr; using std::shared_ptr;
using std::cout; using std::cin; using std::endl;

int main() {

    unique_ptr<int[]> up(new int[10]);
    for (size_t i = 0; i != 10; ++i) {
        up[i] = i;
    }

    up.release(); // automatically uses delete[] to destory its pointer

    shared_ptr<int> sp(new int[10], [](int *p){ delete[] p;});
    for (size_t i = 0; i != 10; ++i) {
        *(sp.get() + i) = i;
    }

    sp.reset();

    return 0;
}

