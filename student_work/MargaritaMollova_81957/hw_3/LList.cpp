#include <iostream>
#include <cassert>

#include "LList.h"

void LList::copyLList (const LList& other)
{
    start = nullptr;
    end = nullptr;
    size = 0;

    Node* current = other.start;
    while (current!=nullptr)
    {
        toEnd (current->data);
        current = current->next;
    }
}

void LList::destroyLList ()
{
    while (start!=nullptr)
    {
        Node* previous = start;
        start = start->next;
        delete previous;
        size--;
    }
}

LList::LList (): start {nullptr}, end {nullptr}, size {0} {}
LList::LList (const LList& other)
{
    this->copyLList(other);
}

LList::~LList ()
{
    this->destroyLList();
}

LList& LList::operator = (const LList& other)
{
    if (this!=&other)
    {
        this->destroyLList();
        this->copyLList(other);
    }

    return *this;
}

int& LList::operator [] (const size_t& index)
{
    return this->at(index)->data;
}

const int& LList::operator [] (const size_t& index) const
{
    return this->at(index)->data;
}

Node* LList::at (const size_t& index) const
{
    assert (index>=0 && index<size);

    size_t curIndex = 0;
    Node* current = start;
    while (curIndex != index)
    {
        current = current->next;
        curIndex++;
    }

    return current;
}

size_t LList::getSize () const
{
    return size;
}

void LList::toStart (const int& _data)
{
    start = new Node (_data, start);
    if (start->next == nullptr)
    {
        end = start;
    }

    size++;
}

void LList::toEnd (const int& _data)
{
    if (start == nullptr)
    {
        end = new Node (_data, nullptr);
        start = end;
    }
    else
    {
        end->next = new Node (_data, nullptr);
        end = end->next;
    }

    size++;
}

void LList::insertAt (const size_t& index, const int& _data)
{
    assert (index>0 && index<size);

    Node* previous = this->at(index-1);
    previous->next = new Node (_data, previous->next);

    size++;
}

void LList::deleteStart ()
{
    assert (size > 0);

    Node* oldStart = start;
    start = start->next;
    delete oldStart;

    if (start == nullptr)
    {
        end = nullptr;
    }

    size--;
}

void LList::deleteEnd ()
{
    if (start == end)
    {
        delete end;
        start = end = nullptr;
    }
    else
    {
        Node* secondLast = this->at(size-2);
        secondLast->next = nullptr;
        delete end;
        end = secondLast;
    }

    size--;
}

void LList::deleteAt (const size_t& index)
{
    assert (index>0 && index<size-1);

    Node* previous = this->at(index-1);
    Node* toBeDeleted = previous->next;
    previous->next = toBeDeleted->next;
    delete toBeDeleted;

    size--;
}

void LList::reverseList ()
{
    assert (size>0);

    Node* previous = nullptr;
    Node* current = start;
    Node* next = current->next;
    
    end = current;
    while (next!=nullptr)
    {
        current->next = previous;
        previous = current;
        current = next;
        next = current->next;
    }
    current->next = previous;
    start = current;
} 

void LList::printLList () const
{
    Node* current = start;
    while (current!=nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}