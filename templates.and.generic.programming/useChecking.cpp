/*
 * useChecking.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

#include "Blob.h"

int main() {
    vector<int> v1(3, 43), v2(10);
    Blob<int> a1(v1.begin(), v1.end()),
              a2 = {0,1,2,3,4,5,6,7,8,9},
              a3(v2.begin(), v2.end());
    cout << a1 << "\n\n" << a2 << "\n\n" << a3 << endl;

    cout << "copy" << "\n\n";
    Blob<int> a5(a1);
    cout << a5 << endl;

    cout << "\nassignmentl" << "\n\n";
    a1 = a3;
    cout << a1 << "\n\n" << a2 << "\n\n" << a3 << endl;

    cout << "\nelement assignment" << "\n\n";
    a1[0] = 42;
    a1[a1.size() - 1] =15;
    cout << a1 << "\n\n" << a3 << endl;

    Blob<string> s1 = {"hi", "bye", "now"};
    BlobPtr<string> p(s1);
    *p = "okay";
    cout << p->size() << endl;
    cout << (*p).size() << endl;

    Blob<string> s2{"one", "two", "three"};
    if (s2[0].empty())
        s2[0] = "empty";
    cout << s2 << endl;
    cout << a1 << endl;
    cout << a2 << endl;
    a2.swap(a1);
    cout << a1 << endl;
    cout << a2 << endl;
    return 0;
}

