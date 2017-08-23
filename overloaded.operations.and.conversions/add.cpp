/*
 * add.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cout; using std::endl; using std::cin;

#include "Sales_data.h"
#include "Sales_item.h"

int main(void) {
    Sales_item item1, item2;
    
    cin >> item2 >> item1;
    cout << item2 + item1 << endl;

    Sales_data data1, data2;
    cin >> data1 >> data2;
    cout << data1 + data2 << endl;
    return 0;
}
