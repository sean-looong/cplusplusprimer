/*
 * unsigned.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

int main() {
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;

    u = 42;
    i = 10;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;

    u = 10;
    i = -42;
    std::cout << i + i << std::endl; // print -84
    std::cout << u + i << std::endl; // if 32-bit ints, prints 4294967264

    i = 10;
    std::cout << "good" << std::endl;
    while (i >= 0) {
        std::cout << i << std::endl; // prints 10 ... 0
        --i;
    }

    for (int i = 10; i <= 0; --i) {
        std::cout << i << std::endl; // prints 10 ... 0
    }

    for (unsigned u = 0; u <= 10; ++u) {
        std::cout << u << std::endl; // prints 0 ... 10
    }

    u = 11;
    while (u > 0) {
        --u;
        std::cout << u << std::endl; // prints 10 ... 0
    }

    u = 10;
    i = -42;

    if (i < u) {
        std::cout << i << std::endl;
    } else {
        std::cout << u << std::endl; // prints 10
    }

    u = 42;
    u2 = 10;
    std::cout << u - u2 << std::endl; // result is 32
    std::cout << u2 - u << std::endl; // result will wrap around

    return 0;
}

