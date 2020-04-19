#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "LinkedList.cpp"
#include "doctest.h"
TEST_CASE("LinkinList")
{
    SUBCASE("reverse with new")
    {
        LinkedList<int> test;
        test.push(1);
        test.push(2);
        test.push(3);
        test.reverse();
        CHECK(test.get_at(0) == 3);
    }
    SUBCASE("1 element reverse")
    {
        LinkedList<int> test;
        test.push(1);
        test.reverse();
        CHECK(test.get_at(0) == 1);
    }
    SUBCASE("reverse with 0")
    {
        LinkedList<int> test;
        test.reverse();
        test.push(1);
        test.push(2);
        test.push(3);
        CHECK(test.get_at(0) == 1);
        CHECK(test.get_at(1) == 2);
        CHECK(test.get_at(2) == 3);
    }

    SUBCASE("reverse 2 with new")
    {
        LinkedList<int> test;
        test.push(1);
        test.push(2);
        test.push(3);
        test.reverse_2();
        CHECK(test.get_at(0) == 3);
    }
    SUBCASE("1 element reverse 2")
    {
        LinkedList<int> test;
        test.push(1);
        test.reverse_2();
        CHECK(test.get_at(0) == 1);
    }
    SUBCASE("reverse 2 with 0")
    {
        LinkedList<int> test;
        test.reverse_2();
        test.push(1);
        test.push(2);
        test.push(3);
        CHECK(test.get_at(0) == 1);
        CHECK(test.get_at(1) == 2);
        CHECK(test.get_at(2) == 3);
    }
}
int main()
{
    doctest::Context().run();
}
