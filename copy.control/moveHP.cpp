/*
 * moveHP.cpp
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

    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
        p.ps = 0;
    }

    HasPtr& operator=(HasPtr rhs) {
        swap(*this, rhs);
        return *this;
    }

    ~HasPtr() {
        delete ps;
    };

private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main(void) {
    HasPtr h("hi mom!");
    HasPtr h2(h);
    h = h2; // h2 is an lvalue, copy constructor used to copy h
    h = std::move(h2); // move constructor moves h2
    return 0;
}

