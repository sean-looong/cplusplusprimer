/*
 * allocPtr.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include <string>
#include <vector>
#include <new>

using std::nothrow;
using std::cout; using std::cin; using std::endl;
using std::string; using std::vector;

size_t get_size() {
    return 42;
}

int main() {

    int *p1 = new int; // if allocation fails, new throws std::bad_alloc
    int *p2 = new (nothrow) int; // if allocation fails, new returns a null pointer

    int i0;
    int *p0 = new int;

    delete p0;

    int i(1024);
    string s(10, '9');
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};

    int *pi = new int(1024);
    string *ps = new string(10, '9');
    vector<int> *pv = new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};

    cout << "*pi: " << *pi
         << "\ti: " << i << endl
         << "*ps: " << *ps
         << "\ts: " << s << endl;

    for (auto b = pv->begin(); b != pv->end(); ++b) {
        cout << *b << " ";
    }
    cout << endl;

    delete pi;
    delete ps;
    delete pv;

    int *pia = new int[get_size()];
    delete[] pia;
    typedef int arrT[42];
    int *p = new arrT;
    delete[] p;
    return 0;
}

