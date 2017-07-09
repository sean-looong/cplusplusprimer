/*
 * Screen.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

class Screen{
public:
    typedef std::string::size_type pos;
    friend class Window_mgr;

    Screen() = default;
    Screen(pos ht, pos wd, char c):
        height(ht), width(wd), contents(std::string(ht * wd, c)) {};
    Screen(pos ht = 0, pos wd = 0):
        height(ht), width(wd), contents(std::string(ht * wd, ' ')) {};

    char get() const {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen& clear(char = bkground);
    Screen& move(pos, pos);
    Screen& set(char);
    Screen& set(pos, pos, char);
    Screen& display(std::ostream& os) {
        do_display(os);
        return *this;
    }
    const Screen& display(std::ostream& os) const {
        do_display(os);
        return *this;
    }

private:
    static const char bkground = ' ';

private:
    void do_display(std::ostream &os) const {
        os << contents;
    }
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

Screen& Screen::clear(char c) {
    contents = std::string(height * width, c);
    return *this;
}

Screen& Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen& Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

#endif

