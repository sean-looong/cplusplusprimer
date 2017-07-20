/*
 * foo.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef FOO_H
#define FOO_H

#include <iostream>

typedef int T;

struct Foo {
    Foo(T t): val(t) {}
    T val;
};

std::ostream& print(std::ostream &os, const Foo &f) {
    os << f.val;
    return os;
}

#endif

