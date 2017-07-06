/*
 * LocalMath.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

// #pragma once

#include "LocalMath.h"

// factorial of val is val * (val - 1) * (val - 2) ... * (val - (val - 1)) * 1
int fact(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}

// factorial of val is val * (val - 1) * (val - 2) ... * (val - (val - 1)) * 1
int factorial(int val) {
    if (val > 1) {
        return factorial(val - 1) * val;
    }

    return 1;
}

// return the greatest common divisor
int gcd(int v1, int v2) {
    while (v2) {
        int temp = v2;
        v2 = v1 % v2;
        v1 = temp;
    }

    return v1;
}


