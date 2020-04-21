#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "LList.cpp"

TEST_CASE("LINKED LIST REVERSE()") {
    LList<int> regular;
    regular.toEnd(1);
    regular.toEnd(2);
    regular.toEnd(3);
    regular.toEnd(4);
    LList<int> regular_copy{regular};            // ------------------------> needed because we want a camparison between a regular and a reversed list
    LList<int> reverse{regular_copy.reverse()};  // ------------------------> and reverse() modifies *this

    SUBCASE("REGULAR SIZE = REVERSE SIZE") {
        CHECK(reverse.getSize() == regular.getSize());
    }
    SUBCASE("REVERSED = BACKWARDS REGULAR") {
        for (size_t i = 0; i < regular.getSize(); i++)
        {
            CHECK(regular[i] == reverse[reverse.getSize() - i - 1]);
        }
    }
    SUBCASE("2xREVERSED = REGULAR") {
        reverse.reverse();
        for (size_t i = 0; i < regular.getSize(); i++)
        {
            CHECK(regular[i] == reverse[i]);
        }
    }
    SUBCASE("FUNCTIONS") {
        SUBCASE("toStart") {
            reverse.toStart(5);
            CHECK(reverse[0] == 5);
            CHECK(reverse.getSize() == 5);
        }
        SUBCASE("toEnd") {
            reverse.toEnd(0);
            CHECK(reverse[4] == 0);
            CHECK(reverse.getSize() == 5);
        }
        SUBCASE("insertElementAt") {
            reverse.insertElementAt(3, 99);
            CHECK(reverse[3] == 99);
            CHECK(reverse[4] == 1);
            CHECK(reverse.getSize() == 5);
        }
    }
}
int main()
{
    doctest::Context().run();
    return 0;
}