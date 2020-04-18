#include "List.h"

void List::copy_l(const List& other)
{
    size = other.size;
    start = end = nullptr;
    Node* current = other.start;
    while(current)
    {
        if(!start)
        {
            start = new Node(current->data);
            end = start;
        }
        else
        {
            end->next = new Node(current->data);
            end = end->next;
        }
        current = current->next;
    }
}

void List::del_l()
{
    while(start)
    {
        Node* copy = start;
        start = start->next;
        delete copy;
    }
}

List::List():start(nullptr),end(nullptr),size(0) {}

List::List(const List& other)
{
    copy_l(other);
}

List& List::operator = (const List& other)
{
    if(this != &other)
    {
        del_l();
        copy_l(other);
    }

    return *this;
}


List::~List()
{
    del_l();
}

size_t List::getSize() const
{
    return size;
}

void List::addData(const int& element)
{
    if(!start)
    {
        start = end = new Node(element);
    }
    else
    {
        end->next = new Node(element);
        end = end->next;
    }
    size++;
}

void List::reverse()
{
    Node* previous = nullptr;
    Node* current = start;
    Node* next = nullptr;

    while(current)
    {
        if(!next) end = start;
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    start = previous;
}

Node* List::dataAt(const size_t index) const 
{
    Node* current = start;
    size_t i = 0;
    while(i < index && current != nullptr)
    {
        current = current->next;
        i++;
    }
    return current;
}

int& List::operator [](size_t index)
{
    return dataAt(index)->data;
}

const int& List::operator [](const size_t index) const
{
    return dataAt(index)->data;
}

void List::print() const
{
    Node* curr = start;
    while(curr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}


