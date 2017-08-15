/*
 * serial.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include <cstddef>

using std::cout; using std::endl; using std::size_t;

struct numbered {
    static size_t sn;
    numbered(): mysn(sn++) {}
    numbered(const numbered&): mysn(sn++) {}
    numbered& operator=(const numbered&) { return *this; }
    size_t mysn;
};

size_t numbered::sn = 0;

void f(numbered s) {
    cout << s.mysn << endl;
}

int main(void) {
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
    return 0;
}

