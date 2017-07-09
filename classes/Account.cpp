/*
 * Account.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <string>
using std::string;

#include "Account.h"

// define static data and function members
const string Account::accountType("Savings Account");
double Account::interestRate = initRate();

void Account::rate(double newRate) {
    interestRate = newRate;
}

