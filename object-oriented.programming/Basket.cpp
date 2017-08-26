/*
 * Basket.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <set>
using std::multiset;
#include <string>
using std::string;
#include <iostream>
using std::ostream; using std::endl; using std::cout;
#include <memory>
#include "Quote.h"
#include "Basket.h"

double Basket::total_receipt(std::ostream& os) const {
    double sum = 0.0;

    for (auto iter  = items.cbegin();
              iter != items.cend();
              iter  = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));         
    }

    os << "Total Sale: " << sum << endl; // print the final overall total
    return sum;
}

void Basket::display(std::ostream& os) const {
    os << "Basket size: " << items.size() << endl;

    // print each distinct ISBN in the Basket along with
    // count of how many copies are ordered and what their price will be
    // upper_bound returns an iterator to the next item in the set
    for (auto next_item  = items.begin();
              next_item != items.end();
              next_item  = items.upper_bound(*next_item)) {
        os << (*next_item)->isbn() << " occurs "
           << items.count(*next_item) << " times"
           << " for a price of "
           << (*next_item)->net_price(items.count(*next_item))
           << endl;
    }
}
