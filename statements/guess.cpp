/*
 * guess.cpp
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

    do {
        cout << "Guess a number between 0 and 9" << endl;
        unsigned i, mynum = 7;

        cin >> i;

        if (i == mynum) {
            cout << "Congrats you guessed right!" << endl;
            break;
        } else {
            if (i < mynum) {
                cout << "too low" << endl;
            } else {
                cout << "too high" << endl;
            }
        }
    } while (true);

    return 0;
}

