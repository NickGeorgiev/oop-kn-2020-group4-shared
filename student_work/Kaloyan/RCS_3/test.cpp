# define DOCTEST_CONFIG_IMPLEMENT
# include <iostream>
# include "LList.cpp"
# include "Doctest/doctest.h"

TEST_CASE("node test") {
    Node<int> first(1);
    Node<int> second(2, &first);
    Node<int> third(3);
    first.next = &third;

    SUBCASE("correct values test"){
        CHECK(first.elem == 1);
        CHECK(second.elem == 2);
        CHECK(third.elem == 3);
        CHECK(second.next == &first);
        CHECK(first.next == &third);
        CHECK(third.next == nullptr);
    }

    SUBCASE("forward test") {
        Node<int>* ptr = &second;
        CHECK(ptr->elem == 2);
        forward(ptr);
        CHECK(ptr->elem == 1);
        forward(ptr);
        CHECK(ptr->elem == 3);
        forward(ptr);
        CHECK(ptr == nullptr);
    }
}

TEST_CASE("toEnd test") {
    LList<double> first;
    first.toEnd(0.1);

    SUBCASE("toEnd on an empty list test") {
        CHECK(first.elemAt(0) == 0.1);
        CHECK(first.getSize() == 1);
    }

    first.toEnd(0.2);
    first.toEnd(0.3);
    first.toEnd(0.4);
    
    SUBCASE("toEnd on a non-empty list") {
        CHECK(first.getSize() == 4);
        for (int i = 0; i < 4; i++) {
            CHECK(first.elemAt(i) == (double)(i+1)/10);
        }
    }
}

TEST_CASE("toStart test") {
    LList<double> first;
    first.toStart(-0.1);

    SUBCASE("toStart on an empty list") {
        CHECK(first.getSize() == 1);
        CHECK(first.elemAt(0) == -0.1);
    }

    first.toStart(-0.2);
    SUBCASE("toStart on a non-empty list") {
        CHECK(first.getSize() == 2);
        CHECK(first.elemAt(0) == -0.2);
        CHECK(first.elemAt(1) == -0.1);
    }
}

TEST_CASE("insertBefore, removeAt test") {
    LList<double> first;
    first.insertBefore(0.2, 0);
    first.insertBefore(0.1, 0);
    first.insertBefore(0.5, 2);
    first.insertBefore(0.3, 2);
    first.insertBefore(0.4, 3);
    
    CHECK(first.getSize() == 5);
    for (int i = 0; i < 5; i++) {
        CHECK(first.elemAt(i) == (double)(i + 1)/10);
    }

    // SUPPOSED TO BREAK:
    // first.insertBefore(9.9, 6);
    // first.removeAt(5);
    // LList<int> second; second.removeAt(0);

    SUBCASE("remove first element test") {
        first.removeAt(0);
        CHECK(first.getSize() == 4);
        CHECK(first.elemAt(0) == 0.2);
    }
    SUBCASE("remove last element test") {
        first.removeAt(4);
        CHECK(first.getSize() == 4);
        CHECK(first.elemAt(3) == 0.4);
    }
    SUBCASE("remove only element test") {
        LList<int> second;
        second.toStart(0);
        second.removeAt(0);
        CHECK(second.getSize() == 0);
    }
}

TEST_CASE("elemAt test") {
    LList<int> first;
    for (int i = 0; i < 5; i++) {
        first.toEnd(i);
    }
    for (int i = 0; i < 5; i++) {
        first.elemAt(i) = i-2;
    }
    for (int i = 0; i < 5; i++) {
        CHECK(first.elemAt(i) == i-2);
    }
    
    // SUPPOSED TO BREAK:
    // first.elemAt(5);
}



TEST_CASE("copy constructor and operator = test") {
    LList<int> first;
    int n = 3;
    for (int i = 0; i < n; i++) {
        first.toEnd(i);
    }

    SUBCASE("copy constructor test") {
        LList<int> second(first);
        CHECK(first.getSize() == second.getSize());
        for (int i = 0; i < second.getSize(); i++) {
            CHECK(first.elemAt(i) == second.elemAt(i));
        }
    }

    SUBCASE("operator = test") {
        LList<int> second = first;
        CHECK(first.getSize() == second.getSize());
        for (int i = 0; i < second.getSize(); i++) {
            CHECK(first.elemAt(i) == second.elemAt(i));
        }
    }

    SUBCASE("operator = trying to assign an object to itself test") {
        first = first;
        CHECK(first.getSize() == n);
        for (int i = 0; i < n; i++) {
            CHECK(first.elemAt(i) == i);
        }
    }
}

TEST_CASE("reverse test") {
    LList<int> first;
    int n = 10;
    for (int i = 0; i < n; i++) {
        first.toEnd(i);
    }
    first.reverse();
    
    CHECK(first.getSize() == n);
    for (int i = 0; i < n; i++) {
        CHECK(first.elemAt(i) == n - 1 - i);
    }
}

int main () {
    doctest::Context().run();
}