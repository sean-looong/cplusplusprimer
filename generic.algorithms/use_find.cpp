/*
 * use_find.cpp
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

#include <iterator>
using std::begin;
using std::end;

#include <algorithm>
using std::find;

int main() {

    int ia[] = {27, 210, 12, 47, 109, 83};
    int val = 83;
    int *result = find(begin(ia), end(ia), val);
    cout << "The value " << val
         << (result == end(ia)? " is not presend": " is presend") << endl;
    // search starting from ia[1] up to but not including ia[4]
    result = find(ia + 1, ia + 4, val);
    cout << "The value " << val
         << (result == ia + 4? " is not presend": " is presend") << endl;

    vector<int> vec = {27, 210, 12, 47, 109, 83};
    val = 42;
    auto result2 = find(vec.cbegin(), vec.cend(), val);
    cout << "The value " << val
         << (result2 == vec.cend()? " is not presend": " is presend") << endl;

    list<string> lst = {"val1", "val2", "val3",};
    string sval = "a value";
    auto result3 = find(lst.cbegin(), lst.cend(), sval);
    cout << "The value " << sval
         << (result3 == lst.cend()? " is not presend": " is presend") << endl;

    return 0;
}

