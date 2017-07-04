/*
 * string_size.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <string>

using std::string;

string st1;
string st2(st1);

int main() {

    string st("The expense of spirit\n");
    cout << "The size of " << st << "is " << st.size() 
         << " characters, including the newline"<< endl;

    return 0;
}

