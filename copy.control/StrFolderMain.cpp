/*
 * FolderMain.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include "StrFolder.h"

#include <iostream>
#include <set>
#include <string>
#include <iostream>
#include <vector>

using std::string; using std::set; using std::cout; using std::endl;
using std::vector;

int main(void) {
    String s1("contents1");
    String s2("contents2");
    String s3("contents3");
    String s4("contents4");
    String s5("contents5");
    String s6("contents6");
    // all new messages, no copies yet
    Message m1(s1);
    Message m2(s2);
    Message m3(s3);
    Message m4(s4);
    Message m5(s5);
    Message m6(s6);

    Folder f1, f2;

    m1.save(f1); m3.save(f1); m5.save(f1);
    m1.save(f2);
    m2.save(f2); m4.save(f2); m6.save(f2);

    m1.debug_print();
    f2.debug_print();

    // create some copies
    Message c1(m1);
    Message c2(m2), c4(m4), c6(m6);

    m1.debug_print();
    f2.debug_print();

    // mow some assignments
    m2 = m3;
    m4 = m5;
    m6 = m3;
    m1 = m5;

    m1.debug_print();
    f2.debug_print();

    vector<Message> vm;
    cout << "capacity: " << vm.capacity() << endl;

    vm.push_back(m1);
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m2);
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m3);
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m4);
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m5);
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m6);
    cout << "capacity: " << vm.capacity() << endl;

    vector<Folder> vf;
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f1);
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f2);
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder(f2));
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder());
    Folder f3;
    f3.save(m6);
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f3);
    cout << "capacity: " << vf.capacity() << endl;

    return 0;
}
