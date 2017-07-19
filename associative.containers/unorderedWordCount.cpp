/*
 * unorderedWordCount.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <unordered_map>
using std::unordered_map;

#include <unordered_set>
using std::unordered_set;

#include <utility>
using std::pair;

#include <string>
using std::string;

int main() {

    unordered_map<string, size_t> word_count;
    string word;

    while (cin >> word) {
        ++word_count[word];
    }

    for (const auto &w: word_count) {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1)? " times": "time")
             << endl;
    }

    return 0;
}

