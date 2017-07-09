/*
 * avg_price.cpp
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
    Sales_data total;

    if (read(cin, total)) {
        Sales_data trans;

        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }

        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }

    return 0;
}

