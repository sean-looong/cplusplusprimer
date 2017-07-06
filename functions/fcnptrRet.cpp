/*
 * fcnptrRet.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

// #pragma once

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);

string::size_type sumLength(const string& s1, const string& s2) {
    return s1.size() + s2.size();
}

string::size_type largerLength(const string& s1, const string& s2) {
    return (s1.size() > s2.size())? s1.size(): s2.size();
}

// three way to declare getFcn
// 1. use decltype for the return type
decltype(sumLength) *getFcn(const string&);
// use trailing return type
auto getFcn(const string&) -> string::size_type(*)(const string&, const string&);
// direct definition
string::size_type (*getFcn(const string&))(const string&, const string&);

// define getFcn
decltype(sumLength) *getFcn(const string &fetch) {
    if (fetch == "sum") {
        return sumLength;
    }
    return largerLength;
}

int main() {
    cout << getFcn("sum")("hello", "world!") << endl;
    cout << getFcn("larger")("hello", "world!") << endl;

    return 0;
}

