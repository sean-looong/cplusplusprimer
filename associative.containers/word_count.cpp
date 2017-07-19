/*
 * word_count.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <map>
using std::map;

#include <set>
using std::set;

#include <utility>
using std::pair;

#include <string>
using std::string;

int main() {

    map<string, size_t> word_count;
    string word;

    while (cin >> word) {
        ++word_count[word];
    }

    for (const auto &w: word_count) {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1)? " times": "time")
             << endl;
    }

    auto map_it = word_count.cbegin();
    while (map_it != word_count.cend()) {
        cout << map_it->first << " occurs " << map_it->second
             << ((map_it->second > 1)? " times": "time")
             << endl;
        ++map_it;
    }

    return 0;
}

