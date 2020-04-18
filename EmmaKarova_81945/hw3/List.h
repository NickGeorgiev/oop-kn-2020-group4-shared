#ifndef _LIST_HH_
#define _LIST_HH_
#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node(const int& _data,Node* _next = nullptr): data(_data),next(_next) {}
};

class List
{
    Node* start;
    Node* end;
    size_t size;

    void copy_l(const List& other);
    void del_l();

    public:
    
    List();
    List(const List& other);
    List& operator = (const List& other);
    ~List();
    size_t getSize() const;
    void addData(const int& element);
    void reverse();
    Node* dataAt(size_t index) const;
    int& operator [](size_t index);
    const int& operator [](size_t index) const;
    void print() const;
};

#endif