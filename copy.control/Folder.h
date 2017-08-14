/*
 * Folder.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef FOLDER_H
#define FOLDER_H

#include <set>
#include <string>

class Folder;

class Message {
friend void swap(Message&, Message&);
friend class Folder;

public:
    explicit Message(const std::string &str=""): contents(str) {}
    ~Message();

    Message(const Message&);
    Message& operator=(const Message&);

    Message(Message&&);
    Message& operator=(Message&&);

    void save(Folder&);
    void remove(Folder&);
    void debug_print();

private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void move_Folders(Message*);
    void remove_from_Folders();
    void addFolder(Folder *f) {
        folders.insert(f);
    }
    void remFolder(Folder *f) {
        folders.erase(f);
    }
};

// declaration for swap should be in the same header as Message itself
void swap(Message&, Message&);

class Folder {
friend void swap(Message&, Message&);
friend class Message;

public:
    ~Folder();

    Folder(const Folder&);
    Folder& operator=(const Folder&);

    Folder(Folder&&);
    Folder& operator=(Folder&&);

    Folder() = default;

    void save(Message&);
    void remove(Message&);
    void debug_print();

private:
    std::set<Message*> msgs; // messages in this folder
    void add_to_Msgs(const Folder&); // add this folder to each message
    void remove_from_Msgs(); // remove this folder from each message
    void addMsg(Message *m) {
        msgs.insert(m);
    }
    void remMsg(Message *m) {
        msgs.erase(m);
    }
    void move_Msgs(Folder*); // move message pointers to point  to this folder
};

#endif

