/*
 * Basket.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef BASKET_H
#define BASKET_H

#include <set>
#include <memory>
#include <iostream>
#include "Quote.h"

class Basket {
public:
    void add_item(const std::shared_ptr<Quote> &sale) {
        items.insert(sale);
    }
    void add_item(const Quote& sale) {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(const Quote&& sale) {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(std::ostream&) const;
    void display(std::ostream&) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();                    
    }

    std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
        items{compare};
};

#endif
