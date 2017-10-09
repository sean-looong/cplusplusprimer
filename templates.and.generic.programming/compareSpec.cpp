/*
 * compareSpec.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <cstring>
using std::strcmp;
#include <iostream>
using std::cout; using std::endl;
#include <functional>
using std::less;

template <typename T> int compare(const T &v1, const T &v2) {
    cout << "compare(T)" << "\t";
    if (less<T>()(v1, v2)) return -1;
    if (less<T>()(v2, v1)) return 1;
    return 0;
}

template <unsigned N, unsigned M> int compare(
        const char (&p1)[N], const char (&p2)[M]) {
    cout << "compare(const char arrays)" << "\t";
    return strcmp(p1, p2);
}

template <> int compare(const char *const& p1, const char* const &p2) {
    cout << "compare(const char* const)" << "\t";
    return strcmp(p1, p2);
}


int main() {
    int *p1 = new int(45);
    int *p2 = new int(42);

    // becuase we are comparing pointer values, the result of
    // this call may vary each time the program is run
    cout << compare(*p1, *p2) << endl;
    cout << compare(p1, p2) << endl;

    cout << strcmp("hi", "mom") << endl;
    cout << compare("hi", "mom") << endl;

    const char *cp1 = "hi", *cp2 = "mom";
    cout << compare(cp1, cp2) << endl;

    return 0;
}

