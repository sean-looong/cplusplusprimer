/*
 * StrVec.h
 *
 * Copyright (C) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E.Moo.
 *
 * Des: This file contains code from "C++ Primer, Fifth Edition"
 */

#ifndef STRVEC_H
#define STRVEC_H

#include <utility>
#include <string>
#include <iostream>
#include <initializer_list>
#include <memory>

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec() noexcept;
    StrVec(std::initializer_list<std::string>);
    void push_back(const std::string&);
    void push_back(std::string&&);
    size_t size() const {
        return first_free - elements;
    }
    size_t capacity() const {
        return cap - elements;
    }
    std::string* begin() const {return elements;}
    std::string* end() const {return first_free;}
    StrVec& operator=(std::initializer_list<std::string>);
    std::string& operator[](std::size_t n) {
        return elements[n];
    }
    const std::string& operator[](std::size_t n) const {
        return elements[n];
    }
    template<class... Args> void emplace_back(Args&&...);
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }
    std::pair<std::string*, std::string*> alloc_n_copy(
            const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

inline StrVec::~StrVec() noexcept {
    free();
}

inline std::pair<std::string*, std::string*> StrVec::alloc_n_copy(
        const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

inline StrVec::StrVec(StrVec &&s) noexcept:
    elements(s.elements), first_free(s.first_free), cap(s.cap){
    s.elements = s.cap = s.first_free = nullptr;
}

inline StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; alloc.destroy(--p)) {
            ;
        }
        alloc.deallocate(elements, cap - elements);
    }
}

inline StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;

        rhs.elements = rhs.cap = rhs.first_free = nullptr;
    }

    return *this;
}

inline StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    cap = first_free = data.second;
    return *this;
}

inline void StrVec::reallocate() {
    auto newcapacity = size()? 2 * size(): 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

inline StrVec::StrVec(std::initializer_list<std::string> il) {
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

inline void StrVec::push_back(std::string &&s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

template<class... Args> inline void StrVec::emplace_back(Args&&... args) {
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif

