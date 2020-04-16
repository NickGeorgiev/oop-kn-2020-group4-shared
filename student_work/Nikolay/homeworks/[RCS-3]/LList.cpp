#include<iostream>
#include<cassert>
#include"LList.h"

template<class T>
void LList<T>::toEnd(const T& elem) {
	if(!start) {
		start = end = new Node<T>(elem);
	}
	else{
		end->next = new Node<T>(elem);
		end = end->next;
	}
	++size;
}

template<class T>
void LList<T>::copy(const LList<T>& other) {
	size = 0;
	start = end = nullptr;
	Node<T>* otherCurr = other.start;
	while(otherCurr) {
		toEnd(otherCurr->elem);
		otherCurr = otherCurr->next;
	}
}

template<class T>
void LList<T>::destroy(){
	while(start) {
		Node<T>* previous = start;
		start = start->next;
		delete previous;
	}
}

template<class T>
LList<T>::LList() : start{nullptr} , end{nullptr} , size{0} {}

template<class T>
LList<T>::LList(const LList<T>& other) {
	copy(other);
}

template<class T>
LList<T>& LList<T>::operator=(const LList<T>& other) {
	if(this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

template<class T>
LList<T>::~LList() {
	destroy();
}

template<class T>
void LList<T>::print() {
	Node<T>* curr = start;
	while(curr) {
		std::cout << curr->elem << " ";
		curr = curr->next;
	}
}

template<class T>
bool LList<T>::empty() const {
	return !start;
}

template<class T>
size_t LList<T>::getSize() const {
	return size;
}

template<class T>
void LList<T>::toStart(const T& elem) {
	if(!start) {
		start = end = new Node<T> (elem,start);
	}
	else{
		start = new Node<T> (elem,start);
	}
	++size;
}

template<class T>
void LList<T>::insertElementAt(const size_t& index,const T& elem) {
	assert(index < size);
	size_t currIndex = 0;
	Node<T>* current = start;
	while(currIndex != index-1 && current) {
		currIndex++;
		current = current->next;
	}
	current->next = new Node<T> (elem,current->next);
	++size;
}

template<class T>
T LList<T>::getElementAt(const size_t& index) const {
	size_t currIndex = 0;
	Node<T>* current = start;
	while(currIndex != index && current) {
		++currIndex;
		current = current->next;
	}
	T result = current->elem;
	return result;
}

template<class T>
void LList<T>::reverse() {
	if(start == end) {
		return;
	}
	Node<T>* previous = start;
	start = start->next;
	previous->next = nullptr;
	reverse();
	end->next = previous;
	end = previous;
}