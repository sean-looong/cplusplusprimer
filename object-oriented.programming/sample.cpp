/*
 * sample.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include "Quote.h"

#include <iostream>
using std::ostream; using std::endl; using std::cout;

int main(void) {
    Quote basic("0-201-54848-8", 45);
    Bulk_quote bulk("0-201-82470-1", 45, 3, .15);

    print_total(cout, basic, 20); // calls Quote::net_price
    print_total(cout, bulk,  20); // calls Bulk_quote::net_price

    Quote base("0-201-82470-1", 50);
    Bulk_quote derived("0-201-82470-1", 50, 5, .19);
    cout << derived.net_price(20); // calls Bulk_quote::net_price
    cout << endl;

    base = derived; // copies the Quote part of derived into base
    cout << base.net_price(20); // calls Quote::net_price
    cout << endl;

    Quote &item = derived; // dynamic and static types of item differ
    cout << item.net_price(20); // calls Bulk_quote::net_price

    item.isbn(); // isbn is not virtual, calls Bulk::isbn
    cout << endl;
    return 0;
}

