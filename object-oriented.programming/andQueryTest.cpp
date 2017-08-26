/*
 * andQueryTest.cpp
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
        string sought1, sought2;
        if (!get_words(sought1, sought2)) break;

        Query andq = Query(sought1) & Query(sought2);
        cout << "\nExecuting Query for: " << andq << endl;
        auto results = andq.eval(file);
        print(cout, results);

        results = Query(sought1).eval(file);
        cout << "\nExecuting Query for: " << Query(sought1) << endl;
        print(cout, results);

        results = Query(sought2).eval(file);
        cout << "\nExecuted query: " << Query(sought2) << endl;
        print(cout, results);
     } while (true);

     return 0;
}

