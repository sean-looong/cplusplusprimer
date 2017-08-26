/*
 * get_print.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include "Query.h"
#include "TextQuery.h"

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <stdexcept>
using std::runtime_error;

#include <iostream>
using std::cin; using std::cout;

TextQuery get_file(int argc, char **argv) {
    ifstream infile;

    if (argc == 2) {
        infile.open(argv[1]);
    }

    if (!infile) {
        throw runtime_error("No input file!");
    }

    return TextQuery(infile);
}

bool get_word(string &s) {
    cout << "enter a word to search for, or q to quit";
    cin >> s;
    if (!cin || s == "q") return false;
    return true;
}

bool get_words(string &s1, string &s2) {
    cout << "enter two words to search for, or q to quit: ";
    cin >> s1;

    // stop if hit eof on input or a "q" is entered
    if (!cin || s1  == "q") return false;
    cin >> s2;
    return true;
}


