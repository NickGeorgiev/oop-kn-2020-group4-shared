#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include<iostream>
#include<cassert>
#include"llist.cpp"

template<class T>
void reverse (Node<T>*& start) {
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

TEST_CASE("Reverse") {
    SUBCASE("Member function") {
        LList<int> llist;
        llist.toEnd(1);
        llist.toEnd(2);
        llist.toEnd(3);
        llist.reverse();
        CHECK(llist[0]==3);
        CHECK(llist[1]==2);
        CHECK(llist[2]==1);
    }
    SUBCASE("Non-member function") {
        LList<int> llist;
        llist.toEnd(1);
        llist.toEnd(2);
        llist.toEnd(3);
        reverse(llist.getStart());
        CHECK(llist[0]==3);
        CHECK(llist[1]==2);
        CHECK(llist[2]==1);
    }
}

int main () {
    doctest::Context().run();

    return 0;
}