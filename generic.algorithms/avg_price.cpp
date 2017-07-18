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

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include "Sales_item.h"

int main() {
    istream_iterator<Sales_item> in_iter(cin), eof;
    ostream_iterator<Sales_item> out_iter(cout, "\n");

    Sales_item sum = *in_iter++;

    while (in_iter != eof) {
        if (sum.isbn() == in_iter->isbn()) {
            sum += *in_iter++;
        } else {
            out_iter = sum;
            sum = *in_iter++;
        }
    }

    out_iter = sum;

    return 0;
}

