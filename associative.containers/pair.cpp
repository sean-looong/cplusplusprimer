/*
 * pair.cpp
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
using std::sort;

#include <map>
using std::map;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

#include <utility>
using std::pair;

#include <string>
using std::string;

#include <vector>
using std::vector;

void preliminaries(vector<string> &v) {
    // process
    istream_iterator<string> input(cin), eof;
    copy(input, eof, back_inserter(v));
    sort(v.begin(), v.end(), [](const string &a, const string &b) {
                return a.size() < b.size();});
}

pair<string, int> process(vector<string> &v) {
    if (!v.empty()) {
        return {v.back(), v.back().size()};
    } else {
        return pair<string, int>(); // explicitly constructed return
    }
}

pair<string, int> process2(vector<string> &v) {
    if (!v.empty()) {
        return make_pair(v.back(), v.back().size());
    } else {
        return pair<string, int>(); // explicitly constructed return
    }
}

pair<string, int> process3(vector<string> &v) {
    if (!v.empty()) {
        return pair<string, int>(v.back(), v.back().size());
    } else {
        return pair<string, int>(); // explicitly constructed return
    }
}

int main() {

    vector<string> v;
    string s;
    while (cin >> s) {
        v.push_back(s);
    }

    preliminaries(v); // sort v into size order

    auto biggest = process(v);
    cout << biggest.first << " " << biggest.second << endl;
    biggest = process2(v);
    cout << biggest.first << " " << biggest.second << endl;
    biggest = process3(v);
    cout << biggest.first << " " << biggest.second << endl;
    return 0;
}

