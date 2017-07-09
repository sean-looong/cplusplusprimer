/*
 * WindowMgr.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef WINDOWMGR_H
#define WINDOWMGR_H

#include <string>
#include <vector>
#include <iostream>
#include "Screen.h"

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;

    // add a Screen to the window and returns its index
    ScreenIndex addScreen(const Screen&);

    void clear(ScreenIndex);
    void resize(Screen::pos r, Screen::pos c, ScreenIndex i);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

inline Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}

inline void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline void Window_mgr::resize(Screen::pos r, Screen::pos c, ScreenIndex i) {
    screens[i].height = r;
    screens[i].width  = c;
    screens[i].contents = std::string(r * c, ' ');
}

#endif

