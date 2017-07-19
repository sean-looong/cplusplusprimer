/*
 * map1.cpp
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

#include <utility>
using std::pair;

#include <string>
using std::string;

int main() {

    map<string, size_t> word_count;

    word_count["Anna"] = 1;
    cout << word_count["Anna"] << endl;
    ++word_count["Anna"];
    cout << word_count["Anna"] << endl;

    // various ways to add word to word_count
    string word;
    word_count.insert({word, 1});
    word_count.insert(make_pair(word, 1));
    word_count.insert(pair<string, size_t>(word, 1));
    word_count.insert(map<string, size_t>::value_type(word, 1));
    typedef map<string, size_t>::value_type valType;
    word_count.insert(valType(word, 1));

    // use value returned by insert
    pair<map<string, size_t>::iterator, bool> insert_ret;
    // if Anna not already in word_count, inert it with value 1
    insert_ret = word_count.insert({"Anna", 1});
    if (insert_ret.second == false) {
        insert_ret.first->second++; // increment current value
    }
    cout << word_count["Anna"] << endl;

    // get an iterator to an element in word_count
    auto map_it = word_count.begin();

    cout << map_it->first; // prints the key for this element
    cout << " " << map_it->second; // prints the value of the element
    ++map_it->second;
    return 0;
}

