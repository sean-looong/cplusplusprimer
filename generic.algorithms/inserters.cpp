/*
 * inserters.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <algorithm>
using std::copy;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iterator>
using std::inserter;
using std::front_inserter;

void print(const string &label, const list<int> &lst) {
    cout << label << endl;
    for (auto iter: lst) {
        cout << iter << " ";
    }
    cout << endl;
}

int main() {

    list<int> lst = {1, 2, 3, 4};
    print("lst", lst);

    list<int> lst2, lst3;
    // after copy completes, lst2 contains 4 3 2 1
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    // after copy completes, lst3 contains 1 2 3 4
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));

    print("lst2", lst2);
    print("lst3", lst3);

    vector<int> v = {1, 2, 3, 4, 5};
    list<int> new_lst = {6, 7, 8, 9};
    auto it = new_lst.begin();

    copy(v.begin(), v.end(), inserter(new_lst, it));
    print("new_lst", new_lst);

    return 0;
}

