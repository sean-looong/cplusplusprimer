/*
 * fileIO.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <stdexcept>
using std::runtime_error;

void process(ifstream &is) {
    string s;
    while (is >> s) {
        cout << s << endl;
    }
}

int main(int argc, char **argv) {
    // for each file passed to the program
    for (auto p = argv + 1; p != argv + argc; ++p) {
        ifstream input(*p); // create input and open the file
        if (input) {
            process(input);
        } else {
            cerr << "couldnot open: " << string(*p) << endl;
        }
    }

    auto p = argv + 1, end = argv + argc;
    ifstream input;
    while (p != end) {
        input.open(*p);
        if (input) {
            process(input);
        } else {
            cerr << "couldnot open: " << string(*p) << endl;
        }
        input.close(); // close file when we're done with it
        ++p;
    }
    return 0;
}

