#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LList.h"

TEST_CASE("Reverse") {
    SUBCASE("Empty") {
        LList<int> list;
        CHECK(list.reverse().getSize() == 0);
    }
    SUBCASE("Size one") {
        LList<int> list;
        list.toEnd(1);

        LList<int> reverse = list.reverse();
        CHECK(reverse.getSize() == list.getSize());
        for (size_t i = 0; i < list.getSize(); i++) {
            CHECK(reverse[i] == list[list.getSize() - 1 - i]);
        }
    }
    SUBCASE("Normal") {
        LList<int> list;
        list.toEnd(1);
        list.toEnd(2);
        list.toEnd(3);
        list.toEnd(4);

        LList<int> reverse = list.reverse();
        CHECK(reverse.getSize() == list.getSize());
        for (size_t i = 0; i < list.getSize(); i++) {
            CHECK(reverse[i] == list[list.getSize() - 1 - i]);
        }
    }
}
