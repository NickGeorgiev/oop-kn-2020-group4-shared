/*Vladimir Toshev Group 4 FN82019*/

#include <iostream>
#include <cassert>
#include "LList.h"

template <class T>
void LList<T>::copyList(const LList<T> &other)
{
    size = 0;
    start = end = nullptr;
    Node<T> *other_current = other.start;
    while (other_current)
    {
        toEnd(other_current->elem);
        other_current = other_current->next;
    }
}

template <class T>
void LList<T>::destroyList()
{
    while (start)
    {
        Node<T> *previous = start;
        start = start->next;
        delete previous;
    }

    start = end = nullptr;
}

template <class T>
LList<T>::LList() : start{nullptr}, end{nullptr}, size{0} {}

template <class T>
LList<T>::LList(const LList<T> &other)
{
    copyList(other);
}

template <class T>
LList<T>::~LList()
{
    destroyList();
}

template <class T>
LList<T> &LList<T>::operator=(const LList &other)
{
    if (this != &other)
    {
        destroyList();
        copyList(other);
    }
    return *this;
}

template <class T>
void LList<T>::print() const
{
    Node<T> *current = start;
    while (current)
    {
        std::cout << current->elem << std::endl;
        current = current->next;
    }
}

template <class T>
void LList<T>::toEnd(const T &element)
{
    if (!start)
    {
        start = end = new Node<T>(element);
    }
    else
    {
        end->next = new Node<T>(element);
        end = end->next;
    }
    size++;
}

template <class T>
void LList<T>::toStart(const T &element)
{
    size++;
    start = new Node<T>(element, start);
    if (!start->next)
    {
        end = start;
    }
}

template <class T>
void LList<T>::insertElementAt(const size_t &index, const T &element)
{
    assert(index < size);
    size_t curr_index = 0;
    Node<T> *current = start;
    while (curr_index != index - 1 && current)
    {
        curr_index++;
        current = current->next;
    }
    current->next = new Node<T>(element, current->next);
}

template <class T>
T LList<T>::popStart()
{
    assert(start != nullptr);

    size--;
    Node<T> *temp = start;

    start = start->next;
    if (size == 0)
    {
        end = nullptr;
    };

    T value = temp->elem;
    delete temp;

    return value;
}

template <class T>
void LList<T>::reverse()
{
    if (start == nullptr || start == end)
    {
        return;
    }

    LList<T> tempList;
    tempList = *this;
    this->destroyList();
    while (tempList.start != nullptr && tempList.end != nullptr)
    {
        this->toStart(tempList.popStart());
    }
}