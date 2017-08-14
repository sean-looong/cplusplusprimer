/*
 * HasPtrValueLike.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <string>
#include <cstddef>

class HasPtr {
friend void swap(HasPtr&, HasPtr&);

public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {}

    HasPtr(const HasPtr &p): ps(new std::string(*p.ps)), i(p.i) {}

    HasPtr& operator=(const HasPtr&);

    ~HasPtr() {
        delete ps;
    };

private:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

HasPtr f(HasPtr hp) {
    HasPtr ret = hp;
    return ret;
}

int main(void) {
    HasPtr h("hi mom!");
    f(h);
    return 0;
}

