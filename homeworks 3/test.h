#ifndef DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "llist.h"
#include "doctest.h"
Element* reverse2(Element* _start){
    Element *current=_start;
Element *after=_start->next;
Element *before=nullptr;
if(_start!=nullptr){
while(after){
    current->next=before;
    before=current;
    current=after;
    after=current->next;
}
current->next=before;
}
return current;
}
TEST_CASE("reverse 1 test")
{
    LinkList l;
    l.toEnd(1);
    l.toEnd(2);
    l.toEnd(3);
    l.toEnd(4);
    CHECK(l.element_at(0) == 1);
    CHECK(l.element_at(1) == 2);
    CHECK(l.element_at(2) == 3);
    CHECK(l.element_at(3) == 4);
    l.reverse();
    CHECK(l.element_at(0) == 4);
    CHECK(l.element_at(1) == 3);
    CHECK(l.element_at(2) == 2);
    CHECK(l.element_at(3) == 1);
}
TEST_CASE("reverse 2 test")
{
    LinkList l;
    l.toEnd(1);
    l.toEnd(2);
    l.toEnd(3);
    l.toEnd(4);
    CHECK(l.element_at(0) == 1);
    CHECK(l.element_at(1) == 2);
    CHECK(l.element_at(2) == 3);
    CHECK(l.element_at(3) == 4);
    Element* _start=reverse2(l.get_start());  
    CHECK(_start->elem == 4);
    _start=_start->next;
    CHECK(_start->elem == 3);
    _start=_start->next;
    CHECK(_start->elem == 2);
    _start=_start->next;
    CHECK(_start->elem == 1);
}

#endif