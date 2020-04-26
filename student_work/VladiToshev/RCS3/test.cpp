/*Vladimir Toshev Group 4 FN82019*/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include <cstring>
#include "LList.cpp"

TEST_CASE("LList")
{
    SUBCASE("getSize")
    {
        SUBCASE("Increase size")
        {
            LList<int> testList;
            CHECK(testList.getSize() == 0);
            testList.toStart(1);
            CHECK(testList.getSize() == 1);
        }
    }

    SUBCASE("popStart")
    {
        SUBCASE("One element")
        {
            LList<int> testList;
            CHECK(testList.getSize() == 0);
            testList.toStart(1);
            CHECK(testList.getSize() == 1);

            CHECK(testList.popStart() == 1);
            CHECK(testList.getSize() == 0);
        }

        SUBCASE("Multiple elements")
        {
            LList<int> testList;
            CHECK(testList.getSize() == 0);
            testList.toStart(1);
            CHECK(testList.getSize() == 1);
            testList.toEnd(2);
            CHECK(testList.getSize() == 2);

            CHECK(testList.popStart() == 1);
            CHECK(testList.getSize() == 1);
            CHECK(testList.popStart() == 2);
            CHECK(testList.getSize() == 0);
        }
    }

    SUBCASE("Reverse")
    {
        SUBCASE("One element")
        {
            LList<int> testList;
            testList.toStart(1);

            testList.reverse();
            CHECK(testList.popStart() == 1);
        }

        SUBCASE("Multiple elements")
        {
            LList<int> testList;
            testList.toStart(1);
            testList.toEnd(2);
            testList.toEnd(3);

            testList.reverse();

            CHECK(testList.popStart() == 3);
            CHECK(testList.popStart() == 2);
            CHECK(testList.popStart() == 1);
        }

        SUBCASE("Multiple elements with insert")
        {
            LList<int> testList;
            testList.toStart(1);
            testList.toEnd(2);
            testList.toEnd(3);
            testList.insertElementAt(1, 9);
            testList.toEnd(4);
            testList.toEnd(5);

            testList.reverse();

            CHECK(testList.popStart() == 5);
            CHECK(testList.popStart() == 4);
            CHECK(testList.popStart() == 3);
            CHECK(testList.popStart() == 2);
            CHECK(testList.popStart() == 9);
            CHECK(testList.popStart() == 1);
        }
    }
}

void run_Tests()
{
    doctest::Context test_context;
    test_context.run();
}

int main()
{
    run_Tests();
}

