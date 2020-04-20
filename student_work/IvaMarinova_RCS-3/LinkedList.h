#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
template <class T>
struct Box 
{
    T data;
    Box* next;
    Box (const T& element): next {nullptr}, data {element} {}
};
template <class T>
class LinkedList 
{
    private:
    Box<T>* head;
    Box<T>* tail;
    size_t size;
    void copy (const LinkedList&);
    void destroy ();

    public:
    LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator= (const LinkedList&);
    ~LinkedList();
    void addBox (const T&);
    void reverse();
    void print() const;


};
#endif
