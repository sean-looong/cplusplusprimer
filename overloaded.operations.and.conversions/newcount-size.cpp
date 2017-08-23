/*
 * newcount-size.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include "make_plural.h"

#include <iostream>
using std::cerr; using std::cin; using std::cout;
using std::endl; using std::ostream;
#include <string>
using std::string;
#include <functional>
using std::bind; using namespace std::placeholders; using std::function;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include <algorithm>
using std::stable_sort; using std::sort; using std::for_each;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

bool GT(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

class SizeComp {
public:
    SizeComp operator=(const SizeComp&) = delete;

    SizeComp(size_t n): sz(n) {}
    bool operator()(const string &s) const {
        return s.size() >= sz;
    }
private:
    size_t sz;
};

class PrintString {
public:
    PrintString(ostream &o): os(o) {}
    void operator()(const string &s) const {os << s << " ";}
private:
    ostream &os;
};

class ShorterString {
public:
    bool operator()(const string &s1, const string &s2) const {
        return s1.size() < s2.size();
    }
};

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    for_each(words.begin(), words.end(), PrintString(cerr));
    cerr << endl;

    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    for_each(words.begin(), words.end(), PrintString(cerr));
    cerr << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);

    stable_sort(words.begin(), words.end(), ShorterString());
    auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " " << sz << " charactoers or longer" << endl;
    for_each(wc, words.end(), PrintString(cout));
    cout << endl;
}

int main(void) {
    vector<string> words;

    string next_word;
    while (cin >> next_word) {
        words.push_back(next_word);
    }

    biggies(words, 6);
    return 0;
}

