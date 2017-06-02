/*
 * add_item2.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item1, item2;
    std::cin >> item1 >> item2;

    if (item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
    } else {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }
    return 0;
}

