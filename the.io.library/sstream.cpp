/*
 * sstream.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <sstream>
using std::istringstream;
using std::ostringstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

struct PersonInfo {
    string name;
    vector<string> phones;
};

string format(const string &s) {
    return s;
}

bool valid(const string &s) {
    // we will see how to validate phone numbers
    // for now just return true
    return true;
}

vector<PersonInfo> getData(istream &is) {
    // will hold a line and word form input, respectively
    string line, word;
    // will hold all the records from the input
    vector<PersonInfo> people;

    while (getline(is, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    return people;
}

ostream& process(ostream &os, vector<PersonInfo> people) {
    for (const auto &entry: people) {
        ostringstream formatted, badNums;

        for (const auto &nums: entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else {
                formatted << " " << format(nums);
            }

            if (badNums.str().empty()) {
                os << entry.name << " "
                   << formatted.str() << endl;
            } else {
                cerr << "input error: " << entry.name
                     << " invalid number(s) " << badNums.str() << endl;
            }
        }
    }

    return os;
}

int main() {
    process(cout, getData(cin));
    return 0;
}

