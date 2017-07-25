/*
 * StrBlob.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;

public:
    using size_type = std::vector<std::string>::size_type;

    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) {
        data->push_back(t);
    }
    void pop_back();

    std::string& front();
    std::string& back();

    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(std::initializer_list<std::string> il):
    data(std::make_shared<std::vector<std::string>>(il)) {
}

class StrBlobPtr {
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz=0): wptr(a.data), curr(sz) {}

    std::string& deref() const;
    StrBlobPtr& incr();
    StrBlobPtr& decr();

private:
    std::shared_ptr<std::vector<std::string>> check(
            size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

inline std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline  std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(
            size_t i, const std::string& msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }

    if (i > ret->size()) {
        throw std::out_of_range(msg);
    }

    return ret;
}

inline StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::decr() {
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

inline bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r) {
        return (!r || lhs.curr == rhs.curr);
    }

    return false;
}

inline bool neq(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return !eq(lhs, rhs);
}

#endif

