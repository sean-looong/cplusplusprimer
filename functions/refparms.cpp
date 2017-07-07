/*
 * refparms.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
string::size_type find_char(const string& s, char c, string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;

    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}

// returns an iterator that refers to the first occurrence of value
// the reference parameter occurs contains a second return value
vector<int>::const_iterator find_val(vector<int>::const_iterator beg,
                                     vector<int>::const_iterator end,
                                     int value,
                                     vector<int>::size_type &occurs) {
    auto res_iter = end;    
    occurs = 0;

    for (; beg != end; ++beg) {
        if (res_iter == end) {
            res_iter = beg;
        }
        ++occurs;
    }

    return res_iter;
}

int main() {

    string s;
    getline(cin, s);
    size_t ctr = 0;
    auto index = find_char(s, 'o', ctr);
    cout << index << " " << ctr << endl;

    vector<int> ivec;
    int i;
    while (cin >> i) {
        ivec.push_back(i);
    }

    for (auto i: {42, 33, 92}) {
        auto it = find_val(ivec.begin(), ivec.end(), i, ctr);
        if (it == ivec.end()) {
            cout << i << " is not in the input data" << endl;
        } else {
            cout << i << " was at position "
                 << it - ivec.begin() << endl;
        }
    }

    return 0;
}

