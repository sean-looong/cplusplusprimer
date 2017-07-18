/*
 * erasemap.cpp
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

#include <string>
using std::string;

int main() {

    map<string, size_t> word_count;
    string word;

    while (cin >> word) {
        ++word_count[word];
    }

    string removal_word = "the";

    // two ways to remove an entry from a map
    // 1. by key
    if (word_count.erase(removal_word)) {
        cout << "ok: " << removal_word << " removed\n";
    } else {
        cout << "oops: " << removal_word << " not found\n";
    }
    // 2. by removing an iterator to the element we want removed
    removal_word = "The";
    map<string, size_t>::iterator where;
    where = word_count.find(removal_word);

    if (where == word_count.end()) {
        cout << "oops: " << removal_word << " not found\n";
    } else {
        word_count.erase(where);
        cout << "ok: " << removal_word << " removed\n";
    }

    return 0;
}

