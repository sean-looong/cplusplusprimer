/*
 * guess.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;

#include "Sales_item.h"

int main() {

    Sales_item item1, item2;

    while (cin >> item1 >> item2) {
        try {
            if (item1.isbn() != item2.isbn()) {
                throw runtime_error("Data must refer to same ISBN");
            }

            cout << item1 + item2 << endl;
        } catch (runtime_error err) {
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n') {
                break;
            }
        }
    }

    return 0;
}

