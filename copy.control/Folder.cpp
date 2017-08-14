/*
 * Folder.cpp
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#include "Folder.h"

#include <iostream>
#include <set>
#include <string>
#include <iostream>

using std::string; using std::set; using std::cerr; using std::endl;

void swap(Message& lhs, Message &rhs) {
    using std::swap; // not strictly needed in this case, but good habit

    for (auto f: lhs.folders) {
        f->remMsg(&lhs);
    }

    for (auto f: rhs.folders) {
        f->remMsg(&rhs);
    }

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f: lhs.folders) {
        f->addMsg(&lhs);
    }

    for (auto f: rhs.folders) {
        f->addMsg(&rhs);
    }
}

Folder::~Folder() {
    remove_from_Msgs();
}

Folder::Folder(const Folder &f): msgs(f.msgs) {
    add_to_Msgs(f);
}

Folder& Folder::operator=(const Folder &f) {
    remove_from_Msgs();
    msgs = f.msgs;
    add_to_Msgs(f);
    return *this;
}


Folder::Folder(Folder &&f) {
    move_Msgs(&f); // make each message point to this folder
}

Folder& Folder::operator=(Folder &&f) {
    if (this != &f) {
        remove_from_Msgs();
        move_Msgs(&f);
    }

    return *this;
}

void Folder::save(Message &m) {
    addMsg(&m);
    m.addFolder(this);
}

void Folder::remove(Message &m) {
    remMsg(&m);
    m.remFolder(this);
}

void Folder::move_Msgs(Folder *f) {
    msgs = std::move(f->msgs);
    f->msgs.clear();
    for (auto m: msgs) {
        m->remFolder(f);
        m->addFolder(this);
    }
}

void Folder::add_to_Msgs(const Folder &f) {
    for (auto msg: f.msgs) {
        msg->addFolder(this);
    }
}

void Folder::remove_from_Msgs() {
    while (!msgs.empty()) {
        (*msgs.begin())->remove(*this);
    }
}

void Folder::debug_print() {
    cerr << "Folder contains " << msgs.size() << " messages" << endl;
    int ctr = 1;
    for (auto m: msgs) {
        cerr << "Message " << ctr++ << ":\t" << m->contents << endl;
    }
}

Message::~Message() {
    remove_from_Folders();
}

Message::Message(const Message &m):
    contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}

Message& Message::operator=(const Message& rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::Message(Message &&m) {
    move_Folders(&m);
}

Message& Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }

    return *this;
}

void Message::save(Folder &f) {
    addFolder(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::move_Folders(Message *m) {
    folders = std::move(m->folders);

    for (auto f: folders) {
        f->remMsg(m);
        f->addMsg(this);
    }

    m->folders.clear();
}

void Message::add_to_Folders(const Message &m) {
    for (auto f: m.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders() {
    for (auto f: folders) {
        f->remMsg(this);
    }
    folders.clear();
}

void Message::debug_print() {
    cerr << "Message:\t" << contents << endl;
    cerr << "Appears in " << folders.size() << " Folders" << endl;
}

