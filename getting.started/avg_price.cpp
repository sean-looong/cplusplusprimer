/*
 * avg_price.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item total;

    if (std::cin >> total) {
        Sales_item trans;

        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;
            } else {
                std::cout << total << std::endl;
                total = trans;
            }
        }

        std::cout << total << std::endl;
    } else {
        std::cout << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}

