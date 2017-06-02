/*
 * mysum.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

int main() {
    int sum = 0, val = 0;

    while (std::cin >> val) {
        sum += val;
    }

    std::cout << "Sum is " << sum << std::endl;

    return 0;
}

