#include<iostream>
#include<cassert>
#include "LList.h"

template<class T>
void LList<T>::copy(const LList<T>& other) 
{
    size = 0;
    start = end = nullptr;
    ListNode<T>* other_current = other.start;
    while(other_current)
    {
        toEnd(other_current->elem);
        other_current = other_current->next;
    }
}

template<class T>
void LList<T>::destroy() 
{    
    while(start)
    {
        ListNode<T>* previous = start;
        start = start->next;
        delete previous;
    }    
}

template<class T>
LList<T>::LList()
{
    start = nullptr;
    end = nullptr;
    size = 0;
}

template<class T>
LList<T>::LList(const LList<T>& other) 
{
    copy(other);
}

template<class T>
LList<T>& LList<T>::operator=(const LList& other) 
{
    if(this != &other) 
    {
        destroy();
        copy();
    }
    return *this;
}

template<class T>
LList<T>::~LList()
{
    destroy(); 
}

template<class T>
void LList<T>::print() const 
{
    ListNode<T>* current = start;
    while(current) 
    {
        std::cout << current->element << std::endl;
        current = current->next;
    }
}

template<class T>
void LList<T>::toEnd(const T& element) 
{
    if(!start)
    {
        start = end = new ListNode<T>(element);
    } else 
    {
        end->next = new ListNode<T>(element);
        end = end->next;
    }
    size++;
}

template<class T>
void LList<T>::toStart(const T& element) 
{
    size++;
    start = new ListNode<T>(element, start);
    if(!start->next) 
    {
        end = start;
    }
}

template<class T>
void LList<T>::Insert(const int& index, const T& element)
{
    assert(index < size);
    int current_index = 0;
    ListNode<T>* current = start;
    while(current_index != index-1 && current) 
    {
        current_index++;
        current = current->next;
    }
    current->next = new ListNode<T>(element, current->next);
}

template<class T>
void LList<T>::reverse()
{
    ListNode<T> *a, *b, *temp;
    a = start;
    if(a != nullptr)
    {
        b = NULL;
        temp = start;
        start = end;
        end = temp;
        while(a != start)
        {
            temp = a->next;
            a->next = b;
            b = a;
            a = temp;
        }
        a->next = b;
    }
}

template<class T>
bool LList<T>::equals(const LList& other1, const LList& other2)
{
    bool equal = false;
    ListNode<T> *a = other1.start;
    ListNode<T> *b = other2.start;

    while (a != nullptr && b != nullptr)
    {
        if (a->element == b->element)
        {
            equal = true;
        }
        else 
        {
            equal = false;
            break;
        }
        a = a->next;
        b = b->next;
    }
    return equal;
}





