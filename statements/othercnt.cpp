/*
 * othercnt.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {

    char ch;
    unsigned vowelCnt = 0;
    unsigned otherCnt = 0;

    while (cin >> ch) {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++vowelCnt;
                break;
            default:
                ++otherCnt;
                break;
        }
    }

    cout << "Number of vowels: " << vowelCnt << "\n"
         << "Total non-vowels: " << otherCnt << endl;

    return 0;
}

