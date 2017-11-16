/*
 * debug_rep.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef DEBUG_REP_H
#define DEBUG_REP_H

#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>

#ifndef SPECIALIZED
std::string debug_rep(const std::string &s);
#ifndef OVERCHAR
std::string debug_rep(char *p);
std::string debug_rep(const char *cp);
#endif // OVERCHAR
#endif // SPECIALIZED

// overloaded, not specialized, function templates
template <typename T> std::string debug_rep(const T &t);
template <typename T> std::string debug_rep(T *p);
template <typename T> std::string debug_rep(T b, T e);
template <typename T> std::string debug_rep(const std::vector<T> &v);

#ifdef SPECIALIZED
template <> std::string debug_rep(const std::string&);
template <> std::string debug_rep(const char*);
template <> std::string debug_rep(char*);
#endif // SPECIALIZED

// print any type we don't otherwise handle
template <typename T> std::string debug_rep(const T &t) {
#ifdef DEBUG
    std::cout << "const T&" << "\t";
#endif // DEBUG
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// print pointers as their pointer value
// followed by the object to which the pointer points
// NB: this function will not work properly with char*
template <typename T> std::string debug_rep(T *p) {
#ifdef DEBUG
    std::cout << "T*" << "\t";
#endif // DEBUG
    std::ostringstream ret;
    ret << "*pointer: " << p;
    if (p) {
        ret << " " << debug_rep(*p);  // print the pointer's own value
    } else {
        ret << " null pointer";
    }

    return ret.str(); // return a copy of the string to which ret is bound
}

#ifndef SPECIALIZED
std::string debug_rep(const std::string &s)
#else
template <> std::string debug_rep(const std::string& s)
#endif // SPECIALIZED
{
#ifdef DEBUG
    std::cout << "const string &" << "\t";
#endif // DEBUG
    return '"' + s + '"'; 
}

#ifndef OVERCHAR
std::string debug_rep(char *p) {
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *cp) {
    return debug_rep(std::string(cp));
}
#endif // OVERCHAR

#ifdef SPECIALIZED 
template <> std::string debug_rep(const char* p) {
    return debug_rep(std::string(p));
}
template <> std::string debug_rep(char* cp) {
    return debug_rep(std::string(cp));
}
#endif // SPECIALIZED 

template <typename T> std::string debug_rep(T b, T e) {
    std::ostringstream ret;
    for (T it = b; it != e; ++it) {
        if (it != b) {
            ret << ",";
        }
        ret << debug_rep(*it);
    }
    return ret.str();
}

template <typename T> std::string debug_rep(const std::vector<T> &v) {
    std::ostringstream ret;
    ret << "vector: [";
    ret << debug_rep(v.begin(), v.end());
    ret << "]";
    return ret.str();
}

#endif // DEBUG_REP_H
