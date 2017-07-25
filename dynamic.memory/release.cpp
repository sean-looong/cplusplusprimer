/*
 * release.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include <string>
#include <memory>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::unique_ptr;

int main() {

    unique_ptr<string> p1(new string("Stegosaurus"));
    // transfers ownership from p1
    // (which points to the string Stegosaurus) to p2
    unique_ptr<string> p2(p1.release()); // release makes p1 null
    cout << *p2 << endl;

    unique_ptr<string> p3(new string("Trex"));
    // reset deletes the memory to which p2 had pointed
    // and transfers ownership from p3 to p2
    p2.reset(p3.release());
    cout << *p2 << endl;

    if (p1) {
        cout << "p1 not null?" << endl;
    }

    if (p3) {
        cout << "p3 not null?" << endl;
    }

    cout << *p2 << endl;
    return 0;
}

