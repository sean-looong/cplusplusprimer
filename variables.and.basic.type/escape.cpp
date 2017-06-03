/*
 * escape.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

int main() {
    std::cout << '\n'; // prints a newline
    std::cout << "\tHi!\n"; // prints a tab followed by "Hi!" and a newline
    std::cout << "Hi \x4dO\115!\n"; // prints Hi MOM! followed by a newline
    std::cout << '\115' << '\n'; // prints M followed by a newline

    return 0;
}

