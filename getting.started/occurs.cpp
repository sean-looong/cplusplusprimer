/*
 * occurs.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 *      显示数字被连续输入的次数
 */

#include <iostream>

int main() {
    int currVal = 0, val = 0;

    // read first number and ensure that we have data to process
    if (std::cin >> currVal) {
        int cnt = 1;

        while (std::cin >> val) {
            if (val == currVal) {
                ++cnt;
            } else {
                std::cout << currVal << " occurs "
                    << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }

        std::cout << currVal << " occurs "
            << cnt << " times" << std::endl;
    }

    return 0;
}

