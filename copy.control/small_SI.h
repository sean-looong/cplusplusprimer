/*
 * small_SI.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef SMALL_SI_H
#define SMALL_SI_H

#include <string>

class Sales_data {
public:
    Sales_data(const std::string& s=""): bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(n*p) {}
    Sales_data(const Sales_data &rhs): bookNo(rhs.bookNo),
        units_sold(rhs.units_sold), revenue(rhs.revenue) {}

    ~Sales_data() {}

    Sales_data& operator=(const Sales_data&);
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::operator=(const Sales_data& rhs) {
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
}

#endif

