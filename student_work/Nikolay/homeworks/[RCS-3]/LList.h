#ifndef __LLIST_HH_
#define __LLIST_HH_
#include<iostream>
template<class T>
struct Node{
	T elem;
	Node* next;

	Node(const T& _elem, Node* _next = nullptr): elem{_elem}, next{_next}{}
};
template<class T>
class LList {
	Node<T>* start;
	Node<T>* end;
	size_t size;

	void copy(const LList<T>&);
	void destroy();
	void rev(Node<T>*);

	public:
	LList();
	LList(const LList<T>&);
	LList& operator=(const LList<T>&);
	~LList();
	void print();
	void toEnd(const T&);
	void toStart(const T&);
	void insertElementAt(const size_t&,const T&);
	void reverse();
};
#endif
