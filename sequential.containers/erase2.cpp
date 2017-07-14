/*
 * erase2.cpp
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

#include <forward_list>
using std::forward_list;

#include <string>
using std::string;

#include <algorithm>
using std::find;

int main() {

    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // print the initial values in lst
    cout << "initial list: ";
    for (const auto it: lst) {
        cout << it << " ";
    }
    cout << endl;

    // erase the odd elements in lst
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it % 2) {
            it = lst.erase(it); // erase this element
        } else {
            ++it;
        }
    }

    // print the currect contents of lst
    cout << "after erasing odd elements from lst ";
    for (const auto it: lst) {
        cout << it << " ";
    }
    cout << endl;

    // repeat the same actions but on a forward_list
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // print the initial values in flst
    cout << "initial list: ";
    for (const auto it: flst) {
        cout << it << " ";
    }
    cout << endl;

    // erase the odd elements in flst
    auto prev = flst.before_begin(); //  element "off the start" of flst
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) {
            curr = flst.erase_after(prev); // erase it and move curr
        } else {
            prev = curr;
            ++curr;
        }
    }

    // print the currect contents of flst
    cout << "after erasing odd elements from flst ";
    for (const auto it: flst) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

