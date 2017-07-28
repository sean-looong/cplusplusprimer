/*
 * TextQuery.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <set>
#include <cstddef>

#include "TextQuery.h"
#include "make_plural.h"

using std::ifstream; using std::istringstream;
using std::vector; using std::string; using std::set;
using std::ispunct; using std::tolower;
using std::ostream; using std::end; using std::cout; using std::endl;
using std::shared_ptr;

TextQuery::TextQuery(ifstream &is): file(new vector<string>) {
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size();
        istringstream line(text);
        string word;

        while (line >> word) {
            word = cleanup_str(word);
            auto &lines = wm[word];
            if (!lines) {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}

string TextQuery::cleanup_str(const string& word) {
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it) {
        if (!ispunct(*it)) {
            ret += tolower(*it);
        }
    }

    return ret;
}

QueryResult TextQuery::query(const std::string& sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(cleanup_str(sought));

    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file); 
    } else {
        return QueryResult(sought, loc->second, file);
    }
}

ostream &print(ostream & os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;

    // print each line in which the word appeared
	for (auto num : *qr.lines) // for every element in the set 
		// don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") " 
		   << *(qr.file->begin() + num) << endl;

	return os;
}

void TextQuery::display_map() {
    auto iter = wm.cbegin(), iter_end = wm.cend();

    for (; iter != iter_end; ++iter) {
        cout << "word: " << iter->first << " {"; 

        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin();
        auto loc_iter_end = text_locs->cend();

        while (loc_iter != loc_iter_end) {
            cout << *loc_iter;

            if (++loc_iter != loc_iter_end) {
                cout << ", ";
            }
        }

        cout << " }\n";
    }

    cout << endl;
}

