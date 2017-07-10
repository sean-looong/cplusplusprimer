/*
 * buf.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void read() {
    // turns on both fail and bad bits
    cin.setstate(cin.badbit | cin.eofbit | cin.failbit);
}

void off() {
    // turns off both fail and bad bits but all other bits unchaned
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
}

int main() {
    cout << "--- before read ---" << endl;
    if (cin.good()) cout << "cin's good" << endl;
    if (cin.bad())  cout << "cin's bad"  << endl;
    if (cin.fail()) cout << "cin's fail" << endl;
    if (cin.eof())  cout << "cin's eof"  << endl;

    read();
    cout << "--- after read ---" << endl;
    if (cin.good()) cout << "cin's good" << endl;
    if (cin.bad())  cout << "cin's bad"  << endl;
    if (cin.fail()) cout << "cin's fail" << endl;
    if (cin.eof())  cout << "cin's eof"  << endl;

    off();
    cout << "--- after off ---" << endl;
    if (cin.good()) cout << "cin's good" << endl;
    if (cin.bad())  cout << "cin's bad"  << endl;
    if (cin.fail()) cout << "cin's fail" << endl;
    if (cin.eof())  cout << "cin's eof"  << endl;

    return 0;
}

