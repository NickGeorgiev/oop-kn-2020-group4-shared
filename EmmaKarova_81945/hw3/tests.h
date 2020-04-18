#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include "List.h"

TEST_CASE("Initializing the list")
{
    SUBCASE("Default constructor")
    {
        List l;

        CHECK(l.getSize() == 0);
    }

    SUBCASE("Adding elements")
    {
        List l;
        l.addData(1);
        l.addData(2);
        l.addData(3);
        l.addData(4);

        CHECK(l.getSize() == 4);
        CHECK(l[0] == 1);
        CHECK(l[1] == 2);
        CHECK(l[2] == 3);
        CHECK(l[3] == 4);
    }
}

TEST_CASE("Reverse function")
{
    List l;
    l.addData(1);
    l.addData(2);
    l.addData(3);
    l.addData(4);

    l.reverse();

    CHECK(l[0] == 4);
    CHECK(l[1] == 3);
    CHECK(l[2] == 2);
    CHECK(l[3] == 1);
}