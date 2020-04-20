#include<iostream>
#include "LinkedList.h"


template<class T>
void LList<T>::copyList(const LList<T>& other) {
    size = other.size;
    start = end = nullptr;
    Node<T>* current = other.start;
    while (current) {
        if (!start) {
            start = new Node<T>(current-> element);
            end = start;
        } else {
            end->next = new Node<T>(current->element);
            end = end-> next;
        }
        current = current->next;
    }
}

template<class T>
void LList<T>::destroyList(){
    while(start){
        Node<T>* previous = start;
        start = start->next;
        delete previous;
    }
}
template<class T>
LList<T>::LList(): start(nullptr), end(nullptr), size(0) {};

template<class T>
LList<T>::LList(const LList<T>& other){
    copyList(other);
}

template<class T>
LList<T>::~LList(){
    destroyList();
}

template<class T>
LList<T>& LList<T>::operator=(const LList& other){
    if(this != &other) {
        destroyList();
        copyList();
    }
}

template<class T>
void LList<T>::print() const{
    Node<T>* current = start;
    while(current) {
        std::cout<<current->element<<std::endl;
        current = current -> next;
    }
}

template<class T>
void LList<T>::toEnd(const T& element) {
    if(!start) {
        start = end = new Node<T>(element);
    } else {
        end-> next = new Node<T>(element);
        end = end -> next;
    }
    size++;
}

template<class T>
void LList<T>::toStart(const T& element){
    size++;
    start = new Node<T>(element,start);
    if (size == 1) {
        end = start;
    }
}

template<class T>
void LList<T>::reverse() {
    Node<T>* previous = nullptr;
    end = start;

	while(start != nullptr) {
		Node<T>* current = start->next;
		start->next = previous;
		previous = start;
		start = current;

    }

	start = previous;

}

template<class T>
size_t LList<T>::getSize() const {
    return size;
}

template <class T>
Node<T>* LList<T>::atStart() const {
    return start;
}

template <class T>
Node<T>* LList<T>::atEnd() const {
    return end;
}

template <class T>
Node<T>* LList<T>::at(const size_t& at) const {
    Node<T>* current=start;

    for(int i = 0; i < at; i++) {
        current = current -> next;
    }

    return current; 
}