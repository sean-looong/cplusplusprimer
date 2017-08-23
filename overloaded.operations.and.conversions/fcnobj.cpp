/*
 * directcall.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin; using std::cout; using std::endl; using std::ostream;
#include <string>
using std::string;
#include <functional>
using std::bind; using namespace std::placeholders; using std::function;
#include <vector>
using std::vector;
#include <algorithm>
using std::count_if;

bool size_compare(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

int main(void) {
    cout << std::plus<int>()(3, 4) << endl;
    std::plus<int> intAdd;
    std::negate<int> intNegate;

    int sum = intAdd(10, 20);
    cout << sum << endl;

    sum = intNegate(intAdd(10, 20));
    cout << sum << endl;

    vector<int> vec = {0, 1, 2, 3, 4, 5, 16, 17 , 18, 19};
    cout << count_if(vec.begin(), vec.end(), 
            bind(std::less_equal<int>(), _1, 10)) << endl;

    vector<string> svec;
    string in;
    while (cin >> in) {
        svec.push_back(in);
    }

    function<decltype(size_compare)> fp1 = size_compare;

    function<bool(const string&)> fp2 = bind(size_compare, _1, 6);
    cout << count_if(svec.begin(), svec.end(), fp2) << endl;
    cout << count_if(svec.begin(), svec.end(), 
            bind(size_compare, _1, 6)) << endl;
    return 0;
}

