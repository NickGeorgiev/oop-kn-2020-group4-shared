#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "LinkedList.h"
#include <cassert>
template <class T>
void LinkedList<T>::copy(const LinkedList<T> &other)
{
    size = 0;
    start = nullptr;
    end = nullptr;
    Box<T> *cycle_other = other.start;
    while (cycle_other != nullptr)
    {
        push(cycle_other->element);
        cycle_other = cycle_other->next;
    }
}

template <class T>
LinkedList<T>::LinkedList()
{
    start = nullptr;
    end = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    while (start != nullptr)
    {
        Box<T> *last = start;
        start = start->next;
        delete last;
    }
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other)
{
    copy(other);
}
template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
    if (this != &other)
    {
        while (start != nullptr)
        {
            Box<T> *last = start;
            start = start->next;
            delete last;
        }
        copy(other);
    }
    return *this;
}
template <class T>
void LinkedList<T>::push(const T &element)
{
    if (start != nullptr)
    {
        end->next = new Box<T>(element);
        end = end->next;
    }
    else
    {
        start = new Box<T>(element);
        end = start;
    }
    size++;
}

template <class T>
void LinkedList<T>::add_to_start(const T &element)
{
    start = new Box<T>(element, start);
    if (size == 0)
    {
        end = start;
    }
    size++;
}

template <class T>
void LinkedList<T>::print() const
{
    Box<T> *cycle = start;
    while (cycle != nullptr)
    {
        std::cout << "->" << cycle->element;
        cycle = cycle->next;
    }
    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::reverse()
{
    Box<T> *cycle = start;
    LinkedList<T> backwards;
    while (cycle != nullptr)
    {
        backwards.add_to_start(cycle->element);
        cycle = cycle->next;
    }
    *this = backwards;
}

template <class T>
void LinkedList<T>::reverse_2() //->1->2->3     1  2->3     1<-2  3     1<-2<-3
{
    if (start != end)
    {
        Box<T> *cycle = start;
        Box<T> *behind = end->next;
        Box<T> *infront = end->next;
        while (cycle != nullptr)
        {
            infront = cycle->next;
            cycle->next = behind;
            behind = cycle;
            cycle = infront;
        }
        start = behind;
    }
}
template <class T>
T const LinkedList<T>::get_at(const int &position) const
{
    assert(position < size);

    Box<T> *cycle = start;
    for (int i = 0; i < position; i++)
    {
        cycle = cycle->next;
    }
    return cycle->element;
}
#endif
