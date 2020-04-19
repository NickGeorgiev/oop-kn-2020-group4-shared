#pragma once
#ifndef _LLIST_H
#define _LLIST_H
#include <iostream>

struct Element{
   int elem;
    Element* next;
     Element(const int& _elem, Element* _next = nullptr): elem{_elem}, next{_next}{}
};

class LinkList{
    Element* start;
    Element* end;
    size_t size;
    void copyList(const LinkList&);
    void destroyList();
    public:
    LinkList();
    LinkList(const LinkList&);
    ~LinkList();
    LinkList& operator=(const LinkList&);
    void print() const;
    void toEnd(const int&);
    void toStart(const int&);
    void insertElementAt(const size_t&,const int&);
    void reverse();
    Element* get_start();
    void set_end(Element* _end);
    void set_size(const size_t& s);
    void set_start(Element* _start);
    int element_at(const size_t&);
};

#endif