/*
 * item_io.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item book;

    std::cin >> book;
    std::cout << book << std::endl;
    return 0;
}

