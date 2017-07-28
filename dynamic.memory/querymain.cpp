/*
 * querymain.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
#include <fstream>
#include <string>

#include "TextQuery.h"
#include "make_plural.h"

using std::ifstream;
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::string;

void runQueries(ifstream &infile) {
    TextQuery tq(infile);

    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") {
            break;
        }
        print(cout, tq.query(s));
    }
}
int main(int argc, char **argv) {
    ifstream infile;

    if (argc < 2 || !(infile.open(argv[1]), infile)) {
       cerr << "No input file!" << endl; 
    }
    runQueries(infile);
    return 0;
}

