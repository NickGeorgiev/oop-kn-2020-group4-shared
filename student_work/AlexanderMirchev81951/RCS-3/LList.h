
#ifndef __LLIST_HH__
#define __LLIST_HH__

#include <iostream>
#include <cassert>


/*
    Implementation from seminar with added function deleteLast.
*/
template <class T>
struct Node
{
    T elem;
    Node *next;
    Node(const T &_elem, Node *_next = nullptr) : elem{_elem}, next{_next} {}
};

template <class T>
class LList
{
    Node<T> *start;
    Node<T> *end;
    size_t size;

    void copyList(const LList<T> & other)
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
    void destroyList()
    {
        while (start)
        {
            Node<T> *previous = start;
            start = start->next;
            delete previous;
        }
    }

public:

    LList() : start{nullptr}, end{nullptr}, size{0} {}

    LList(const LList<T> &other)
    {
        copyList(other);
    }

    ~LList()
    {
        destroyList();
    }

    LList<T> &operator=(const LList &other)
    {
        if (this != &other)
        {
            destroyList();
            copyList();
        }
        LList tmp(other);
        swapList(tmp);
        return *this;
    }

    const T& operator[](const int pos) const {
        assert(pos < size);
        if(pos == 0) return this->start->elem;
        if(pos == size-1) return this->end->elem;

        Node<T>* current = this->start;
        for (size_t i = 0; i < pos; i++)
        {
            current = current->next;
        }
        return current->elem;
    }

    const size_t& getSize() const {
        return this->size;
    }

    void print() const
    {
        Node<T> *current = start;
        while (current)
        {
            std::cout << current->elem << std::endl;
            current = current->next;
        }
    }

    void toEnd(const T &element)
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

    void toStart(const T &element)
    {
        size++;
        start = new Node<T>(element, start);
        if (!start->next)
        {
            end = start;
        }
    }
    void insertElementAt(const size_t &index, const T &element)
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

    T popLast() 
    {
        assert(size > 0);
        if(size == 1)
        {
            T res = this->start->elem;
            delete this->start;
            this->start = nullptr;
            this->end = nullptr;
            this->size = 0;
            return res;
        }

        Node<T> *current = start;
        for (size_t i = 0; i < size - 2; i++)
        {
            current = current->next;
        }

        T res = this->end->elem;
        delete this->end;
        current->next = nullptr;
        this->end = current;
        size --;

        return res;
    }
    LList<T> reverse() const {
        LList<T> res;
        for (int i = size - 1 ; i >= 0; --i)
        {
            res.toEnd(operator[](i));
        }
        return res;
    }
};
#endif
