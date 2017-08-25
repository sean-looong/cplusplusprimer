/*
 * useQuote.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include "Quote.h"

#include <iostream>
using std::ostream; using std::endl; using std::cout;

int main(void) {
    Quote base("0-201-82470-1", 50);
    print_total(cout, base, 10); // calls Quote::net_price

    Bulk_quote derived("0-201-82470-1", 50, 5, .19);
    print_total(cout, derived, 10); // calls Bulk_quote::net_price

    Quote *baseP = &derived;
    // calls the version from the base class
    // regardless of the dynamic type of baseP
    double undiscounted = baseP->Quote::net_price(42);
    return 0;
}

