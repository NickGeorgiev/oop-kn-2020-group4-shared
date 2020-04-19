#include <iostream>
#include "llist.h"
#include<cassert>

void LinkList::copyList(const LinkList& other){
  size =other.size;
    start = end = nullptr;
    Element* other_current = other.start;
    while(other_current){
        toEnd(other_current->elem);
        other_current = other_current->next;
    }
}

void LinkList::destroyList(){
   while(start){
        Element* previous = start;
        start = start->next;
        delete previous;
    }  
}

LinkList::LinkList():start{nullptr}, end{nullptr}, size{0} {}

LinkList::LinkList(const LinkList& other) {
    copyList(other);
}

LinkList::~LinkList(){
    destroyList(); 
}

LinkList& LinkList::operator=(const LinkList& other) {
    if(this != &other) {
        destroyList();
        copyList(other);
    }
    LinkList tmp(other);
    copyList(tmp);
    return *this;
}


void LinkList::print() const {
    Element* current = start;
    while(current) {
        std::cout << current->elem << std::endl;
        current = current->next;
    }
}


void LinkList::toEnd(const int& element) {
    if(!start){
        start = end = new Element(element);
    } else {
        end->next = new Element(element);
        end = end->next;
    }
   
    size++;
}


void LinkList::toStart(const int& element) {
    size++;
    start = new Element(element, start);
    if(!start->next) {
        end = start;
    }
}

void LinkList::insertElementAt(const size_t& index, const int& element){
    assert(index < size);
    size_t curr_index = 0;
    Element* current = start;
    while(curr_index != index-1 && current) {
        curr_index++;
        current = current->next;
    }
    current->next = new Element(element, current->next);
}

void LinkList::reverse(){
Element *current=start;
Element *after=start->next;
Element *before=nullptr;
while(current!=end){
    current->next=before;
    before=current;
    current=after;
    after=current->next;
}
current->next=before;
after=end;
before=start;
end=before;
start=after;
}

Element* LinkList::get_start(){return start;}
void LinkList::set_end(Element* _end){end=_end;}
void LinkList::set_size(const size_t& s){size=s;}
void LinkList::set_start(Element* _start){start=_start;}
int LinkList::element_at(const size_t&n){
    Element* current=start;
    for(int i=0;i<n;++i){
        current=current->next;}
        return current->elem; 
}
