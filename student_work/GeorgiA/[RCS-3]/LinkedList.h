#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
template <class T>
struct Box
{
    T element;
    Box *next;
    Box(const T &added_element, Box *new_next = nullptr) : element{added_element}, next{new_next} {}
};

template <class T>
class LinkedList
{
private:
    Box<T> *start;
    Box<T> *end;
    int size;

    void copy(const LinkedList<T> &);

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &other);
    LinkedList<T> &operator=(const LinkedList<T> &other);
    void push(const T &element);
    void add_to_start(const T &element);
    void print() const;
    void reverse();
    void reverse_2();
    T const get_at(const int &position) const;
};
#endif
