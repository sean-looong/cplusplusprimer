/*
 * wordQueryTest.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include "Query.h"
#include "TextQuery.h"

#include <string>
using std::string;
#include <set>
using std::set;
#include <iostream>
using std::cin; using std::cerr; using std::cout; using std::endl;

int main(int argc, char **argv) {
    TextQuery file = get_file(argc, argv);

    do {
        string sought;
        if (!get_word(sought)) break;

        Query name(sought) ;
        const auto results = name.eval(file);
        cout << "\nExecuting Query for: " << name << endl;
        print(cout, results);
     } while (true);

     return 0;
}

