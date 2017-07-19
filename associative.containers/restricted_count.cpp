/*
 * restricted_count.cpp
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
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    string word;

    while (cin >> word) {
        if (exclude.find(word) == exclude.end()) {
            ++word_count[word];
        }
    }

    for (const auto &w: word_count) {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1)? " times": "time")
             << endl;
    }

    return 0;
}

