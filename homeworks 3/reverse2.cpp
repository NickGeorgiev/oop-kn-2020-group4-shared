/*#ifndef _REVERSE_2_CPP
#define _REVERSE_2_CPP
#include "llist.h"
LinkList reverse2(Element* _start){
    LinkList l;
    size_t _size;
    l.set_end(_start);
    Element *current=_start;
Element *after=_start->next;
Element *before=nullptr;
if(_start!=nullptr){
while(after){
    current->next=before;
    before=current;
    current=after;
    after=current->next;
    ++_size;
}
current->next=before;
++_size;
l.set_start(current);
l.set_size(_size);
}

return  l;
}
#endif*/