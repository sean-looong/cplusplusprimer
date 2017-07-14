/*
 * stack.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stack>
using std::stack;

int main() {

    stack<int> intStack;

    for (size_t ix = 0; ix != 10; ++ix) {
        intStack.push(ix);
    }

    while (!intStack.empty()) {
        int value = intStack.top();
        cout << value << " ";
        intStack.pop();
    }
    cout << endl;

    return 0;
}

