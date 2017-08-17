/*
 * StrVec.c
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include "StrVec.h"

#include <string>
#include <memory>

using std::string;
using std::allocator;

allocator<string> StrVec::alloc;

