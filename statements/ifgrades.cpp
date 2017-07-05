/*
 * ifgrades.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
vector<unsigned> grades;

string goodVers(string lettergrade, unsigned grade) {
    if (grade % 10 > 7) {
        lettergrade += '+';
    } else {
        if (grade % 10 < 3) {
            lettergrade += '-';
        }
    }

    return lettergrade;
}

string badVers(string lettergrade, unsigned grade) {
    if (grade % 10 > 3) {
        if (grade % 10 > 7) {
            lettergrade += '+';
        }
    } else  {
        lettergrade += '-';
    }

    return lettergrade;
}

string rightVers(string lettergrade, unsigned grade) {
    if (grade % 10 > 3) {
        if (grade % 10 > 7) {
            lettergrade += '+';
        }
    } else  {
        lettergrade += '-';
    }

    return lettergrade;
}

int main() {

    unsigned grade;
    
    while (cin >> grade) {
        grades.push_back(grade);
    }

    for (auto it: grades) {
        cout << it << " ";
        string lettergrade;
        if (it < 60) {
            lettergrade = scores[0];
        } else {
            lettergrade = scores[(it - 50) / 10];
            if (it != 100) {
                if (it % 10 > 7) {
                    lettergrade += '+';
                } else if (it % 10 < 3) {
                    lettergrade += '-';
                }
            }
        }
        cout << lettergrade << endl;
        if (it > 59 && it != 100) {
            cout << "alternative version: " << it << " ";
            lettergrade = scores[(it - 50) / 10];
            cout << goodVers(lettergrade, it) << " ";
            cout << badVers(lettergrade, it) << " ";
            cout << rightVers(lettergrade, it) << " ";
            cout << endl;
        }
    }

    return 0;
}

