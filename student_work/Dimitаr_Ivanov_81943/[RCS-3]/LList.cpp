#include <iostream>
#include "LList.h"
#include <cassert>

template <class T>
void LList<T>::copyList(const LList<T>& other){
    // size = other.size;
    size = 0;
    start = end = nullptr;
    Node<T>* other_current = other.start;
    Node<T>* self_current = start; // pazim starta. ne iskame de se promenq
    while(other_current){                                // zamestvame
    //     if (!start) {// vliza samo vednuzh v nachaloto
    //         start = new Node<T>(other_current->elem);
    //         end = start;
    //     } else {
    //         end->next = new Node<T>(other_current->elem);
    //         end = end->next;
    //     }
    //     other_current = other_current -> next;
        toEnd(other_current->elem);
        other_current = other_current->next;
    }
}
template <class T>
void LList<T>::destroyList(){
    // Node<T>* previous = start;
    while(start){
        Node<T>* previous = start;
        start = start -> next;
        delete previous;
    }
}

//primerno kanonichno predstavqne

template <class T>
LList<T>::LList():start{nullptr}, end{nullptr}, size{0} {}

template <class T>
LList<T>::LList(const LList<T>& other){
    copyList(other);
}

template <class T>
LList<T>::~LList(){
    destroyList();
}

template <class T>
LList<T>& LList<T>::operator= (const LList& other){ //& vrushtame obekt po referenciq
    if (this != &other) { // ako ne e samiqt this
        destroyList();
        copyList();
    }
    // LList tmp(other); 
    // swaplist(tmp);   // alternative
    return *this;
}

// void swapList(LList& other) {
//     std::swap(start, other.start);
//     std::swap(end, other.end);
//     std::swap(size, other.size);
// }

template<class T>
void LList<T>::print() const {
    Node<T>* current = start;
    while(current) {
        std::cout << current->elem << std::endl;
        current = current -> next;
    }
}

template<class T>
void LList<T>::toEnd(const T& element) {
    if (!start) {
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
    if (!start->next) {
        end = start;
    }
}

template<class T>
Node<T>* LList<T>::getStart () const {
    return start;
}

template<class T>
void LList<T>::reverse() {
    if (size == 0) {
        return;
    }

    LList<T> new_list;

    Node<T>* current = start;
    while (current) {
        new_list.toStart(current->elem);
        current = current -> next;
    }

    destroyList();
    *this = new_list;
}

template<class T>
void LList<T>::insertElementAt(const size_t& index, const T& element) {
    assert(index < size);
    
    //1->2->124->3->4
    size_t curr_index = 0;
    Node<T>* current = start;
    while (curr_index != index && current) {
        curr_index++;
        current = current->next;
    }
    current->next = new Node<T>(element, current->next);

    //alternative addition
    // 1->2->3->124->4

    // while (curr_index != index && current) {
    //     curr_index++;
    //     current = current->next;
    // }
    // current->next = new Node<T>(element, current->next);
    // std::swap(current->elem,current->next->elem);
}