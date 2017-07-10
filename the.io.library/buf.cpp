/*
 * buf.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cout;
using std::endl;
using std::ends;
using std::flush;
using std::unitbuf;
using std::nounitbuf;

int main() {
    // writes hi and  a newline, then flushes the buffer
    cout << "hi!" << endl;
    // writes hi, then flushes the buffer; add no data
    cout << "hi" << flush;
    // writes hi and a null, then flushes the buffer
    cout << "hi" << ends;

    cout << unitbuf; // all writes will be flushed immediately
    // andy out is flushed immediately, no buffering
    cout << "first" << "second" << endl;
    cout << nounitbuf; // returns to normal buffering

    return 0;
}

