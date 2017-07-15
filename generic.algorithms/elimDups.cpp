/*
 * elimDups.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <functional>
using std::bind;
using std::ref;
using namespace std::placeholders;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::for_each;

// comparision function to be used to sort by word length
bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

bool LT(const string &s1, const string &s2) {
    return s1 < s2;
}

void print(const vector<string> &words) {
    for_each(words.begin(), words.end(),
        [](const string &s) { cout << s << " "; });
    cout << endl;
}

int main() {

    vector<string> words;

    // copy contents of each book into a single vector
    string next_word;
    while (cin >> next_word) {
        words.push_back(next_word);
    }
    print(words);

    vector<string> cpy = words;
    // uses string < to compare elements
    // sort and print the vector
    sort(words.begin(), words.end(), LT);
    print(words);

    words = cpy;

    // eliminate duplicates
    sort(words.begin(), words.end());
    auto it = unique(words.begin(), words.end());
    words.erase(it, words.end());
    
    // sort by length using a function
    stable_sort(words.begin(), words.end(), isShorter);
    print(words);

    // use bind to invert isShorter to sort longest to shortest
    sort(words.begin(), words.end(), bind(isShorter, _2, _1));
    print(words);

    return 0;
}

