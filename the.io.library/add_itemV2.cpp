/*
 * add_itemV2.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include "Sales_data.h"

int main() {
    Sales_data data1, data2;

    if (read(cin, data1) && read(cin, data2)) {
        if (data1.isbn() == data2.isbn()) {
            Sales_data sum = add(data1, data2);
            print(cout, sum);
            cout << endl;
        }
    } else {
        cout << "Input failed!" << endl;
    }

    return 0;
}

