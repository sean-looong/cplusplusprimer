/*
 * String.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <cstring>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <memory>

#include "String.h"

using std::uninitialized_copy;
using std::initializer_list;
using std::ostream;

std::allocator<char> String::a;

String& String::operator=(const String &rhs) {
    auto newp = a.allocate(rhs.sz);
    uninitialized_copy(rhs.p, rhs.p+rhs.sz, newp);
    if (p) {
        a.deallocate(p, sz);
    }
    p = newp;
    sz = rhs.sz;
    return *this;
}

String& String::operator=(String&& rhs) noexcept {
    if (this != &rhs) {
        if (p) {
            a.deallocate(p, sz);
        }
        p = rhs.p;
        sz = rhs.sz;
        rhs.p = nullptr;
        rhs.sz = 0;
    }

    return *this;
}

String& String::operator=(const char *cp) {
    if (p) {
        a.deallocate(p, sz);
    }
    p = a.allocate(sz = std::strlen(cp));
    uninitialized_copy(cp, cp + sz, p);
    return *this;
}

String& String::operator=(char c) {
    if (p) {
        a.deallocate(p, sz);
    }
    p = a.allocate(sz = 1);
    *p = c;
    return *this;
}

String& String::operator=(initializer_list<char> il) {
    if (p) {
        a.deallocate(p, sz);
    }
    p = a.allocate(sz = il.size());
    uninitialized_copy(il.begin(), il.end(), p);
    return *this;
}

ostream& print(ostream& os, const String &s) {
    auto p = s.begin();
    while (p != s.end()) {
        os << *p++;
    }
    return os;
}

String add(const String& lhs, const String& rhs) {
    String ret;
    ret.sz = lhs.sz + rhs.sz;
    ret.p = String::a.allocate(ret.sz);
    uninitialized_copy(lhs.begin(), lhs.end(), ret.p);
    uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
    return ret;
}

String make_plural(size_t ctr, const String &word, const String &ending) {
    return (ctr != 1)? add(word, ending): word;
}

ostream& operator<<(ostream &os, const String &s) {
    return print(os, s);
}

String operator+(const String &lhs, const String &rhs) {
    return add(lhs, rhs);
}
