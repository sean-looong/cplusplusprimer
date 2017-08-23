/*
 * Sales_data.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
friend std::ostream& operator<<(std::ostream&,const Sales_data&);
friend std::istream& operator>>(std::istream&, Sales_data&);
friend bool operator==(const Sales_data&, const Sales_data&);

public:
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p) {}
    Sales_data(std::istream&);

    std::string isbn() const {return bookNo;}
    Sales_data& operator+=(const Sales_data&);
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
};

inline bool operator==(const Sales_data& lhs, const Sales_data& rhs) {
    return lhs.isbn() == rhs.isbn() &&
           lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

inline bool operator!=(const Sales_data& lhs, const Sales_data& rhs) {
    return !(lhs == rhs);
}

Sales_data operator+(const Sales_data&, const Sales_data&);
std::ostream& operator<<(std::ostream&,const Sales_data&);
std::istream& operator>>(std::istream&, Sales_data&);

#endif

