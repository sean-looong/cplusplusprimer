/*
 * Quote.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>

class Quote {
friend std::istream& operator>>(std::istream&, Quote&);
friend std::ostream& operator<<(std::ostream&, Quote&);
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }

    // virtual destructor needed
    // if a base pointer poointing to a derived object is deleted
    virtual ~Quote() = default; // dynamic binding for the destructor

    std::string isbn() const {
        return bookNo;
    }

    // returns the total sales price for the specified number of items
    // derived classes will override and apply different discount algorithms
    virtual double net_price(std::size_t n) const {
        return n * price;
    }

    // virtual function to return a dynamically allocated copy of itself
    virtual Quote* clone() const & {
        return new Quote(*this);
    }
    virtual Quote* clone() && {
        return new Quote(std::move(*this));
    }
private:
    std::string bookNo; // ISBN number of this item
protected:
    double price = 0.0; // normal, undiscunted price
};

// abstract base class to hold the discount rate and quantity
// derived classes will implement pricing strategies using these data
class Disc_quote: public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price,
               std::size_t qty, double disc):
               Quote(book, price),
               quantity(qty), discount(disc) { }

    double net_price(std::size_t) const = 0;
    std::pair<size_t, double> discount_polity() const {
        return {quantity, discount};
    }
protected:
    std::size_t quantity = 0; // purchase size for the discount to apply
    double discount = 0.0;    // fractional discount to apply
};

// the discount kicks in when a specified number of copyies of the same book are sold
// the discount is expressed as a fraction used to reduce the normal price
class Bulk_quote: public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p,
               std::size_t qty, double disc): Disc_quote(book, p, qty, disc) { }
    double net_price(std::size_t) const override;
    Bulk_quote* clone() const & {
        return new Bulk_quote(*this);
    }
    Bulk_quote* clone() && {
        return new Bulk_quote(std::move(*this));
    }
};

// discount (a fraction off list) for only a specified number of copies,
// additional copies sold at standard price
class Lim_quote: public Disc_quote {
public:
    Lim_quote(const std::string& book="", double p=0.0,
              std::size_t qty=0, double disc_rate=0.0): Disc_quote(book, p, qty, disc_rate) { }
    double net_price(std::size_t) const;
    Lim_quote* clone() const & {
        return new Lim_quote(*this);
    }
    Lim_quote* clone() && {
        return new Lim_quote(std::move(*this));
    }
};

double print_total(std::ostream &, const Quote&, std::size_t);

#endif
