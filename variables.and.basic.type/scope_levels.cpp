/*
 * scope_levels.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

int reused = 42; // reused has global scope

int main() {

    int unique = 0;

    // print 42 0
    std::cout <<  reused << " " << unique << std::endl;

    int reused = 0; // new local object named reused hides global reused

    // print 0 0
    std::cout <<  reused << " " << unique << std::endl;

    // explicitly requests the global reused;
    // print 42 0
    std::cout << ::reused << " " << unique << std::endl;

    return 0;
}

