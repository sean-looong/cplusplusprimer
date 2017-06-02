/*
 * whilecount.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

int main() {
    int sum = 0, val = 1;
    // keep executing the while as long as val is less than or equal to 10
    while (val <= 10) {
        sum += val;
        ++val;
    }

    std::cout << "Sum of 1 to 10 inclusive is "
        << sum << std::endl;

    return 0;
}

