#include <iostream>
#ifndef LLIST_H
#define LLIST_H

template<class T>
struct Node{
    T elem;
    Node* next;

    Node(const T& _elem, Node* _next = nullptr): elem{_elem}, next{_next} {}
};

template<class T>
class LList{

    Node<T>* start;
    Node<T>* end;
    size_t size;
    void copyList(const LList<T>&);
    void destroyList();

public:
    LList();
    LList(const LList&);
    ~LList();

    void toEnd(const T&);
    void toStart(const T&);
    void insertElementAt(const size_t&, const T&);
    void print() const;

    const size_t getSize() const;
    LList& reverse();

    LList& operator=(const LList&);
    const T operator[](const size_t& pos) const;
};
#endif