/*
 * useScreen.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Screen.h"

int main() {
    Screen myScreen(5, 3);
    // move the cursor to a given position, and set that character
    myScreen.move(4, 0).set('#');

    Screen nextScreen(5, 5, 'X');
    nextScreen.move(4, 0).set('#').display(cout);
    cout << endl;

    const Screen blankScreen(5, 3);
    myScreen.set('#').display(cout); // calls nonconst version
    cout << endl;
    blankScreen.display(cout); // calls const version
    cout << endl;

    myScreen.clear('Z').display(cout);
    cout << endl;
    myScreen.move(4, 0);
    myScreen.set('#');
    myScreen.display(cout); // calls nonconst version
    cout << endl;
    myScreen.clear('Z').display(cout);
    cout << endl;
    
    // if move returns Screen not Screen&
    Screen temp = myScreen.move(4, 0);
    temp.set('#');
    myScreen.display(cout);
    cout << endl;

    return 0;
}

