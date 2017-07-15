/*
 * bind2.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iterator>
using std::istream_iterator;

#include <algorithm>
using std::for_each;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <functional>
using std::bind;
using std::ref;
using namespace std::placeholders;

ostream &print(ostream &os, const string &s, char c) {
    return os << s << c;
}

int main() {

    string s;
    vector<string> words;

    while (cin >> s) {
        words.push_back(s);
    }

    for_each(words.begin(), words.end(), bind(print, ref(cout), _1, ' '));
    cout << endl;

    ofstream os("data/outFile1");
    for_each(words.begin(), words.end(), bind(print, ref(os), _1, ' '));
    cout << endl;
    os.close();

    ifstream is("data/outFile1");
    istream_iterator<string> in(is), eof;
    for_each(in, eof, bind(print, ref(cout), _1, '\n'));
    cout << endl;
    is.close();

    return 0;
}

