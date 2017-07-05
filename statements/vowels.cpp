/*
 * vowel.cpp
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
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    while (cin >> ch) {
        switch (ch) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            default:
                break;
        }
    }

    cout << "Number of vowels a: " << aCnt << "\n"
         << "Number of vowels e: " << eCnt << "\n"
         << "Number of vowels i: " << iCnt << "\n"
         << "Number of vowels o: " << oCnt << "\n"
         << "Number of vowels u: " << uCnt << endl;

    return 0;
}

