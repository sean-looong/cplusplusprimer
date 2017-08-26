/*
 * scope.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::endl; using std::cout;

struct Base {
    Base(): mem(0) { }
protected:
    int mem;
};

struct Derived: Base {
    Derived(int i): mem(i) { }
    int get_mem() {
        return mem;
    }
    int get_base_mem() {
        return Base::mem;
    }
protected:
    int mem; // hides mem in the base
};

int main(void) {
    Derived d(42);
    cout << d.get_mem() << endl;
    cout << d.get_base_mem() << endl;
    return 0;
}

