/*
 * convs.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

int main() {
    int i = 42;
    std::cout << i << std::endl; // prints 42

    if (i) { // condition will evaluate as true
        i = 0;
    }

    std::cout << i << std::endl; // prints 0

    bool b = 42; // b is true
    std::cout << b << std::endl; // prints 1

    int j = b; // j has value 1
    std::cout << j << std::endl; // prints 1

    double pi = 3.14;
    std::cout << pi << std::endl; // prints 3.14

    j = pi;
    std::cout << j << std::endl; // prints 3

    unsigned char c = -1; // assuming 8-bit chars, c ahs value 255
    i = c;
    std::cout << i << std::endl; // prints 255

    return 0;
}

