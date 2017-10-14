/*
 * build.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <string>
using std::string;

#include "Blob.h"
#include "compare.h"

// instantiation file must provide a (nonextern) definition for every
// type and function that other files declare as extern
template class Blob<string>;
template class Blob<int>;
template int compare(const int&, const int&);

