/*
 * erase1.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <string>
using std::string;

#include <algorithm>
using std::find;

int main() {

    list<string> slist;
    string s;

    while (cin >> s) {
        slist.push_back(s); // read the contents into slist
    }

    auto iter = find(slist.begin(), slist.end(), "Quasimodo");
    if (iter != slist.end()) {
        slist.erase(iter);
    }

    auto orig = slist; // keep a copy before we destory the contents
    slist.clear(); // delete all the elements within the container
    cout << "after clear, size is: " << slist.size() << endl;

    slist = orig; // restore the data
    slist.erase(slist.begin(), slist.end()); // equivalent
    cout << "after clear, size is: " << slist.size() << endl;

    slist = orig;
    auto elem1 = slist.begin(), elem2 = slist.end();
    // delete the range of elements between two iterators
    // return an iterator to the element just after the last removed element
    elem1 = slist.erase(elem1, elem2); // after the call elem1 == elem2
    cout << "after erase elem1 to elem2 size is: " << slist.size() << endl;

    if (elem1 != elem2) {
        cout << "something wrong" << endl;
    } else {
        cout << "okay, they're equal" << endl;
    }

    return 0;
}

