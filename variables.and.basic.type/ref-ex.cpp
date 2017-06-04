/*
 * ref-ex.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

int main() {
    int i = 0, &ri = i; // ri is a reference to i
    // ri is just another name for i;
    std::cout << i << " " << ri << std::endl;
    i = 5;
    std::cout << i << " " << ri << std::endl;
    ri = 10;
    std::cout << i << " " << ri << std::endl;

    return 0;
}

