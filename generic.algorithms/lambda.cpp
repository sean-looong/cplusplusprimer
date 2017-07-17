/*
 * lambda.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <iterator>
using std::inserter;

#include <algorithm>
using std::for_each;
using std::transform;

void fcn1() {
    size_t v1 = 42;
    // copies v1 into the callable object named f
    auto f = [v1]{ return v1; };
    v1 = 0;
    auto j = f(); // j is 42, f stored a copy of v1 when we created it
    cout << j << endl;
}

void fcn2() {
    size_t v1 = 42;
    // the object f2 contains a reference to v1
    auto f2 = [&v1]{ return v1; };
    v1 = 0;
    auto j = f2(); // j is 0, f2 refers to v1; it doesn't store it
    cout << j << endl;
}

void fcn3() {
    size_t v1 = 42;
    // f can change the value of the variables it captures
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f(); // j is 43
    cout << j << endl;
}

void fcn4() {
    size_t v1 = 42;
    // we can change that variables through the reference inside f2
    auto f2 = [&v1] { return ++v1; };
    v1 = 0;
    auto j = f2(); // j is 1
    cout << j << endl;
}

void fcn5() {
    size_t v1 = 42;
    size_t* const p = &v1;
    // increments v1, the object to which p points
    auto f = [p]() { return ++*p; };
    auto j = f(); // j is 43
    cout << v1 << " " << j << endl;
    v1 = 0;
    j = f();
    cout << v1 << " " << j << endl;
}

int main() {

    fcn1();
    fcn2();
    fcn3();
    fcn4();
    fcn5();

    return 0;
}

