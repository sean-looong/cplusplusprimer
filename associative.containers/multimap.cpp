/*
 * multimap.cpp
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
using std::multimap;

#include <utility>
using std::pair;

#include <string>
using std::string;

int main() {

    multimap<string, string> authors;
    // add data
    authors.insert({"Alain de Botton", "On Love"});
    authors.insert({"Alain de Botton", "Status Anxiety"});
    authors.insert({"Alain de Botton", "Art of Travel"});
    authors.insert({"Alain de Botton", "Architecture of Happiness"});

    string search_item("Alain de Botton");
    auto entries = authors.count(search_item); // number of elements
    auto iter    = authors.find(search_item); // first entry for this author

    while (entries) {
        cout << iter->second << endl;
        ++iter;
        --entries;
    }

    cout << endl;

    for (auto beg = authors.lower_bound(search_item),
              end = authors.upper_bound(search_item);
         beg != end;
         ++beg) {
        cout << beg->second << endl;     
    }

    cout << endl;

    for (auto pos = authors.equal_range(search_item);
         pos.first != pos.second;
         ++pos.first) {
        cout << pos.first->second << endl;     
    }

    return 0;
}

