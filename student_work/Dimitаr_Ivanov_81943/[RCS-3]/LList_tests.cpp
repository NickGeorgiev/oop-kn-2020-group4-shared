#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include "LList.cpp"

TEST_CASE ("reverse function test") {
    LList<int> elems;

    elems.toEnd(1);
    elems.toEnd(2);
    elems.toEnd(3);
    elems.toEnd(4);
    elems.toEnd(5);

    Node<int>* current = elems.getStart();
    size_t num = 1;
    while(current) {
        CHECK(current->elem == num);
        current = current -> next;
        num++;
    }

    elems.print();

    elems.reverse();
    
    current = elems.getStart();
    num = 5;
    while(current) {
        CHECK(current->elem == num);
        current = current -> next;
        num--;
    }

    elems.print();

}

int main()
{
    doctest::Context().run();
    return 0;
}