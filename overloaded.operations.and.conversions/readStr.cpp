/*
 * directcall.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin; using std::cout; using std::endl;
using std::cerr; using std::istream; using std::ostream;
#include <string>
using std::string;
#include <functional>
using std::bind; using namespace std::placeholders; using std::function;
#include <vector>
using std::vector;
#include <algorithm>
using std::count_if;

class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' '):
        os(o), sep(c) {}
    void operator()(const string &s) const {
        os << s << sep;
    }
private:
    ostream &os;
    char sep;
};

class ReadLine {
public:
    ReadLine(istream &i): is(i) {}
    bool operator()(string &s) const {
        return std::getline(is, s)? true: false;
    }
private:
    istream &is;
};

int main(void) {
    vector<string> vs;
    ReadLine rl(cin);
    string s;
    while (rl(s)) {
        vs.push_back(s); 
    }

    cout << "read: " << vs.size() << " elements" << endl;
    PrintString printer;
    printer(s);

    PrintString errors(cerr, '\n');
    errors(s);

    cerr << "for_each printing to cerr" << endl;
    for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
    return 0;
}
