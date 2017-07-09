/*
 * Sales_data.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::istream; using std::ostream;

#include "Sales_data.h"


Sales_data::Sales_data(std::istream& is) {
    read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    if (bookNo == rhs.bookNo) {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
    }

    return *this;
}

double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    }

    return 0;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::ostream &print(std::ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

std::istream &read(std::istream& is, Sales_data& item) {
    double price;

    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

