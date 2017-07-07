/*
 * printFcn.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef PRINTFCN_H
#define PRINTFCN_H

#include <cstddef>
#include <iterator>
#include <vector>

void print(const char *cp);
void print(const char *beg, const int *end);
void print(std::vector<int>::const_iterator beg,
           std::vector<int>::const_iterator end);
void print(const int ia[], std::size_t size);
void print(const std::vector<int>&);

inline foo() {
    int j[2] = {0, 1};
    print("Hello World");
    print(j, std::end(j) - std::begin(j))
    print(std::begin(j), std::end(j));
}

#endif

