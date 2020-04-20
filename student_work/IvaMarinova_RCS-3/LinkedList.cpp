#include "LinkedList.h"
#include <iostream>

template <class T>
void LinkedList<T>::copy(const LinkedList<T>& other)
{
    size = other.size;
    head = tail = nullptr;
    Box<T>* current = other.head;
    while (current)
    {
        addBox(current->data);
        current = current->next;
    }
}

template <class T>
void LinkedList<T>::destroy()
{
    while (head)
    {
        Box<T>* current = head;
        head = head->next;
        delete current;
    }
}
template <class T>
LinkedList<T>::LinkedList(): head {nullptr}, tail {nullptr}, size {0} {}
template <class T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
    copy(other);
}
template <class T>
LinkedList<T>::~LinkedList()
{
    destroy();
}
template <class T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
}

template <class T>
void LinkedList<T>::addBox (const T& element)
{
    if (!head)
    {
        head = new Box<T> (element);
        tail = head;
    }
    else 
    {
        tail->next = new Box<T> (element);
        tail = tail->next;
    }
    tail->next = nullptr;
}
template <class T>
void LinkedList<T>::print() const
{
    Box<T>* current = head;
    while (current)
    {
        std::cout << current->data << " "; 
        current = current->next;
    }
}


template <class T>
void LinkedList<T>::reverse ()
{
    Box<T>* current = head;
    tail = head;
    Box <T>* previous;
    Box <T>* next;
    while (current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
    tail->next = nullptr;
}
