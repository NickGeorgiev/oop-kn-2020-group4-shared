#include <iostream>
#include "LList.h"

void LList::copyList(const LList& other){
	this->size = other.size;
	head = nullptr;
	end = nullptr;

	Node *temp = other.head;

	while(temp != nullptr){

		if(head == nullptr){
			head = new Node();
			head->data = temp->data;
			end = head;
		} else {
			end->next = new Node();
			end->next->data = temp->data;
			end = end->next;
		}

		temp = temp->next;
	}
}

void LList::deleteList(){
	while(head != nullptr){
		Node* temp = head;
		head = head->next;
		
		delete temp;
	}
}

int LList::getHeadNodeData() const{
	int data = head->data;
	return data;
}

int LList::getEndNodeData() const{
	int data = end->data;
	return end->data;
}

LList::LList(): head{nullptr}, end{nullptr}, size{0} {}

LList::LList(const LList& other){
	copyList(other);
}

LList::~LList(){
	deleteList();
}

LList& LList::operator=(const LList& other){
	if(this != &other){
		deleteList();
		copyList(other);
	}
	return *this;
}

void LList::addNewEnd(int data){
	Node *newEnd = new Node();
	newEnd->data = data;

	if(head == nullptr){
		head = end = newEnd;
	} else {
		Node *temp = head;
		while(temp->next != nullptr){
			temp = temp->next;
		}
		temp->next = newEnd;
	}

	size++;
}

void LList::addNewHead(int data){
	Node *n = new Node();   
	n->data = data;             
	n->next = head;         

	head = n;    

	size++;           
}

void LList::print() const{
	Node *temp = head;

	while(temp != nullptr){
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}

void LList::reverse(){

	Node *prev = nullptr;

	while(head != nullptr){
		Node *temp = head->next;
		head->next = prev;
		prev = head;
		head = temp;
	}
	head = prev;
}

void LList::create(int *arr, size_t arrSize){
	addNewHead(arr[0]);

	for(int i = 1; i < arrSize; i++){
		addNewEnd(arr[i]);
	}
	size = arrSize;
}

