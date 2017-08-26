/*
 * vecBasket.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::ostream; using std::endl; using std::cout;
#include <memory>
using std::shared_ptr; using std::make_shared;
#include "Quote.h"
#include "Basket.h"

int main() {
    Quote base("0-201-82470-1", 50);
    Bulk_quote bulk("0-201-54848-8", 50, 10, .25);

    vector<Quote> basket;
    basket.push_back(Quote("0-201-82470-1", 50));
    // ok, bug copies only the Quote part of the object into basket
    basket.push_back(Bulk_quote("0-201-54848-8", 50, 10, .25));
    cout << basket.back().net_price(15) << endl;

    vector<shared_ptr<Quote>> basket2;
    basket2.push_back(make_shared<Quote>("0-201-82470-1", 50));
    basket2.push_back(
        make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));

    cout << basket2.back()->net_price(15) << endl;
    return 0;
}
