/*
 * scope.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::endl; using std::cout;

class Base {
public:
    virtual int fcn();
};

int Base::fcn() { cout << "Base::fcn()" << endl; return 0; }

struct D1: public Base {
public:
    // hides fcn in the base; this fcn is not virtual
    int fcn(int);
    virtual void f2();
};

int D1::fcn(int) { cout << "D1::fcn(int)" << endl; return 0; }
void D1::f2() { cout << "D1::f2()" << endl; }

class D2 final: public D1 {
public:
    int fcn(int); // nonvirtual function hides D1::fcn(int)
    int fcn();    // overrides virtual fcn from Base
    void f2();    // overrides virtual f2 from D1
};

int D2::fcn(int) { cout << "D2::fcn(int)" << endl; return 0; }
int D2::fcn() { cout << "D2::fcn()" << endl; return 0; }
void D2::f2() { cout << "D2::f2()" << endl; }

int main(void) {
    D1 dobj, *dp = &dobj;
    dp->fcn(42); // call to D1:fun(int)

    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn(); // call Base::fcn at run time
    bp2->fcn(); // call Base::fcn at run time
    bp3->fcn(); // call D2::fcn at run time

    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
    d1p->f2(); // will call D1::f2()
    d2p->f2(); // will call D2::f2()

    D1 *p1 = &d2obj;
    D2 *p2 = &d2obj;
    p1->fcn(42); // calls D1::fcn(int)
    p2->fcn(42); // calls D2::fcn(int)
    return 0;
}

