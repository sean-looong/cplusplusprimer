/*
 * equal.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::equal;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

int main() {

    list<const char *> roster1;
    vector<string> roster2;

    roster1 = {"hello", "so long"};
    roster2 = {"hello", "so long", "tata"};

    auto b = 
        // roster2 should have at least as many elements as roster1
        equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());

    (b)? cout << "true": cout << "false";
    cout << endl;

    return 0;
}

