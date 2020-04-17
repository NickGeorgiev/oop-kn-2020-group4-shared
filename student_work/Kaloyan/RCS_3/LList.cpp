#ifndef __LLIST_CPP__
#define __LLIST_CPP__

#include<iostream>
#include<cassert>
#include "LList.h"

template<class T>
void forward(Node<T>*& node) {
    node = node->next;
}

template<class T>
void LList<T>::destroy() {
    while(start) {
        removeAt(0);
    }
}

template<class T>
void LList<T>::copy(const LList& other) {
    start = end = nullptr;
    size = 0;
    Node<T>* current = other.start;
    while(current) {
        toEnd(current->elem);
        forward(current);
    }
}

template<class T>
Node<T>* LList<T>::nodeAt(const size_t& place) {
    assert(place < size);

    if (place == 0) {
        return start;
    }
    else if (place == size - 1) {
        return end;
    }
    else {
        Node<T>* current = start;
        for (int i = 0; i < place; i++) {
            forward(current);
        }
        return current;
    }
}

template<class T>
LList<T>::~LList() {
    destroy();
}

template<class T>
LList<T>::LList(const LList& other) {
    copy(other);
}

template<class T>
LList<T>& LList<T>::operator=(const LList& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}


template<class T>
void LList<T>::toEnd(const T& _elem) {
    if (!start) {
        start = end = new Node<T>(_elem);
    }
    else {
        end->next = new Node<T>(_elem);
        end = end->next;
    }
    size++;
}

template<class T>
void LList<T>::toStart(const T& elem) {
    start = new Node<T>(elem, start);
    if (!(start->next)) {
        end = start;
    }
    size++;
}

template<class T>
void LList<T>::insertBefore(const T& _elem, const size_t& place) {
    assert(place <= size);
    
    if (place == 0) {
        toStart(_elem);
    } 
    else if (place == size) {
        toEnd(_elem);
    }
    else {
        Node<T>* node = new Node<T>(_elem, nodeAt(place));
        nodeAt(place - 1)->next = node;
        size++;
    }
}

template<class T>
void LList<T>::removeAt(const size_t& place) {
    assert(start);
    assert(place < size);

    Node<T>* toBeRemoved;
    if (place == 0) {
        toBeRemoved = start;
        if (size == 1) {
            start = end = nullptr;
        }
        else {
            forward(start);
        }
    }
    else if (place == size - 1) {
        toBeRemoved = end;
        end = nodeAt(size - 2);
        nodeAt(size - 2)->next = nullptr;
    }
    else {
        toBeRemoved = nodeAt(place);
        nodeAt(place - 1)->next = nodeAt(place + 1);
    }
    delete toBeRemoved;
    size--;
}

template<class T>
T& LList<T>::elemAt(const size_t& place) {
    assert(place < size);

    return nodeAt(place)->elem;
}

template<class T>
size_t LList<T>::getSize() const {
    return size;
}

template<class T>
void LList<T>::reverse() {
    if(start && size > 1) {
        Node<T>* current = start;
        LList reversed;
        while (current) {
            reversed.toStart(current->elem);
            forward(current);
        }
        *this = reversed;
        reversed.destroy();
    }
}

# endif 