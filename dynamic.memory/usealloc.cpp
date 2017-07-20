/*
 * usealloc.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include <memory>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::allocator;
using std::cout; using std::cin; using std::endl;

int main() {
    const size_t n = 100;
    allocator<string> alloc; // object that can allocate strings
    auto p = alloc.allocate(n); // allocate n unconstructed strings

    auto q = p; // q will point to one past the last constructed element
    alloc.construct(q++); // *q is the empty string
    cout << *(q - 1) << endl;

    alloc.construct(q++, 10, 'c'); // *q is cccccccccc
    cout << *(q - 1) << endl;

    alloc.construct(q++, "hi"); // *q is hi
    cout << *(q - 1) << endl;

    cout << *p << endl; // ok: uss the string output operator
    while (q != p) {
        alloc.destroy(--q); // free the strings we actually allocated
    }

    alloc.deallocate(p, n); // return the memory we allocated

    p = alloc.allocate(n);
    string s;
    ifstream in("data/storyDataFile");
    while (in >> s && q != p + n) {
        alloc.construct(q++, s);
    }

    size_t size = q - p;

    cout << "read " << size << " strings" << endl;

    for (q = p + size - 1; q != p; --q) {
        alloc.destroy(q);
    }

    alloc.deallocate(p, n);
    in.close();

    in.open("data/storyDataFile");
    p = new string[n];
    q = p;
    while (in >> s && q != p + n) {
        *q++ = s;
    }
    size = q - p;
    cout << "read " << size << " strings" << endl;

    delete[] p;


    return 0;
}

