/*
 * qm.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <string>
using std::string;

#include "Blob.h"
#include "compare.h"

// these template types must be instantiated elsewhere in the program
// instantion declaretion and definition
extern template class Blob<string>;
extern template int compare(const int&, const int&);

int main() {
    Blob<string> sa1, sa2; // instantiation will appear elsewhere
    // Blob<int> and its initializer_list constructor
    // are instantiated in this file
    Blob<int> a1 = {0,1,2,3,4,5,6,7,8,9};
    Blob<int> a2(a1); // copy constructor instantiated in this file

    compare(a1[0], a2[0]); // instantiation will appear elsewhere
    return 0;
}

