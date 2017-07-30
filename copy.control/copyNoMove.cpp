/*
 * copyNoMove.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <utility>
#include <iostream>

class Foo {
public:
    Foo() = default;
    Foo(const Foo&); // copy constructor
    // other members, but Foo does not define a move constructor
};

Foo::Foo(const Foo&) { std::cout << "Foo copy ctor" << std::endl; }

int main() {

    Foo x;
    Foo y(x);            // copy constructor; x is an lvalue
    Foo z(std::move(x)); // copy constructor, because there is no move
    return 0;
}

