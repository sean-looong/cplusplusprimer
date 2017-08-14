/*
 * HasPtrUseCount.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <string>
#include <cstddef>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

    HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) {
        ++*use;
    }

    HasPtr& operator=(const HasPtr&);

    ~HasPtr();

private:
    std::string *ps;
    int i;
    std::size_t *use; // member to track how many objects share *ps
};

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete use;
        delete ps;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    ++*rhs.use;

    if (--*use == 0) {
        delete use;
        delete ps;
    }

    use = rhs.use;
    ps  = rhs.ps;
    i   = rhs.i;
    return *this;
}

HasPtr f(HasPtr hp) {
    HasPtr ret;
    ret = hp;
    return ret;
}

int main(void) {
    HasPtr h("hi mom!");
    HasPtr h2 = h; // no mew memory is allocated
    return 0;
}

