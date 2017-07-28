/*
 * make_plural.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef MAKE_PLARA_H
#define MAKE_PLARA_H

#include <cstddef>
#include <string>

inline std::string make_plural(std::size_t ctr,
    const std::string &word, const std::string &ending) {
    return (ctr > 1)? word + ending: word;    
}


#endif

