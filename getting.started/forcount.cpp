/*
 * forcount.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

int main() {
    int sum = 0;

    for (int val = 1; val <= 10; ++val) {
        sum += val;
    }

    std::cout << "Sum of 1 to 10 inclusive is "
        << sum << std::endl;

    return 0;
}

