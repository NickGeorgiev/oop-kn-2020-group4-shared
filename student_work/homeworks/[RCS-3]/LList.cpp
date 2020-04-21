#include "LList.h"
#include<iostream>
#include<cassert>

template<class T>
void LList<T>::copyList(const LList<T>& other) {
    size = 0;
    start = end = nullptr;
    Node<T>* other_current = other.start;
    while(other_current){
        toEnd(other_current->elem);
        other_current = other_current->next;
    }
}

template<class T>
void LList<T>::destroyList() {    
    while(start){
        Node<T>* previous = start;
        start = start->next;
        delete previous;
    }    
}

template<class T>
LList<T>::LList():start{nullptr}, end{nullptr}, size{0} {}

template<class T>
LList<T>::LList(const LList<T>& other) {
    copyList(other);
}

template<class T>
LList<T>::~LList(){
    destroyList(); 
}

template<class T>
LList<T>& LList<T>::operator=(const LList& other) {
    if(this != &other) {
        destroyList();
        copyList(other);
    }
    return *this;
}

template<class T>
const T LList<T>::operator[](const size_t& pos) const {
    size_t count{0};
    Node<T>* current = start;

    while(count < pos) {
        current = current->next;
        count++;
    }

    return current->elem;
}

template<class T>
void LList<T>::print() const {
    Node<T>* current = start;
    while(current) {
        std::cout << current->elem << std::endl;
        current = current->next;
    }
}

template<class T>
void LList<T>::toEnd(const T& element) {
    if(!start){
        start = end = new Node<T>(element);
    } else {
        end->next = new Node<T>(element);
        end = end->next;
    }
    size++;
}

template<class T>
void LList<T>::toStart(const T& element) {
    size++;
    start = new Node<T>(element, start);
    if(!start->next) {
        end = start;
    }
}
template<class T>
void LList<T>::insertElementAt(const size_t& index, const T& element){
    assert(index < size);
    size_t curr_index = 0;
    Node<T>* current = start;
    while(curr_index != index-1 && current) {
        curr_index++;
        current = current->next;
    }
    current->next = new Node<T>(element, current->next);
    size++;
}

template<class T>
const size_t LList<T>::getSize() const {
    return size;
}

template<class T>
LList<T>& LList<T>::reverse() {
    assert(size >= 2);
    LList temp;
    Node<T>* current = start;
    while(current) {
        temp.toStart(current->elem);
        current = current->next;
    }
    *this = temp;
    return *this;
}