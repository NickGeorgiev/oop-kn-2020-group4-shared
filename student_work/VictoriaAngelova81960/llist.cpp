#include "LList.h"

template<class T>
void LList<T>::copyList (const LList<T>& other) {
    size = 0;
    start = end = nullptr;
    Node<T>* other_current = other.start;
    while(other_current){
        toEnd(other_current->elem);
        other_current = other_current->next;
    }
}

template<class T>
void LList<T>::destroyList () {    
    while(start){
        Node<T>* previous = start;
        start = start->next;
        delete previous;
    }    
}

template<class T>
Node<T>* LList<T>::at (size_t pos)
{
    assert(start!= nullptr);
    Node<T>* current = start;
    while(pos>0 && current!= nullptr)
    {
        current= current->next;
        --pos;
    }
    assert (current != nullptr);    
    return current;
}

template<class T>
LList<T>::LList() : start{nullptr}, end{nullptr}, size{0} {}

template<class T>
LList<T>::LList (const LList<T>& other) {
    copyList(other);
}

template<class T>
LList<T>::~LList () {
    destroyList(); 
}

template<class T>
LList<T>& LList<T>::operator = (const LList& other) {
    if(this != &other) {
        destroyList();
        copyList();
    }
}

template<class T>
Node<T>*& LList<T>::getStart () {
    return start;
}

template<class T>
void LList<T>::print () const {
    Node<T>* current = start;
    while(current) {
        std::cout << current->elem << std::endl;
        current = current->next;
    }
}

template<class T>
void LList<T>::toEnd (const T& element) {
    if(!start){
        start = end = new Node<T>(element);
    } else {
        end->next = new Node<T>(element);
        end = end->next;
    }
    size++;
}

template<class T>
void LList<T>::toStart (const T& element) {
    size++;
    start = new Node<T>(element, start);
    if(!start->next) {
        end = start;
    }
}

template<class T>
void LList<T>::reverse () {
    Node<T>* previous = nullptr;
    Node<T>* next = nullptr;
    while(start) {
        next=start->next;
        start->next=previous;
        previous=start;
        start=next;
    }
    start=previous;
}

template<class T>
void LList<T>::insertElementAt (const size_t& index, const T& element){
    assert(index < size);
    size_t curr_index = 0;
    Node<T>* current = start;
    while(curr_index != index-1 && current) {
        curr_index++;
        current = current->next;
    }
    current->next = new Node<T>(element, current->next);
}

template<class T>
T& LList<T>::operator[] (const size_t& i)
{
    return at(i)->elem;
}

template<class T>
T LList<T>::operator[] (const size_t& i) const
{
    return at(i)->elem;
}
