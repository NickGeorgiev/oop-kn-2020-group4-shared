#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <iostream>
#include <cstring>
#include "String.h"

TEST_CASE("c_str test") {
    String first("test");
    String second;
    CHECK(strcmp(first.c_str(), "test") == 0);
    CHECK(strcmp(second.c_str(), "") == 0);

}
TEST_CASE("size & capacity test") {
    String first;
    String second("wassup");

    CHECK(first.capacity() == 1);
    CHECK(first.size() == 0);
    CHECK(second.capacity() == 7);
    CHECK(second.size() == 6);
}
TEST_CASE("operator = test") {
    String first("test");
    String second = first;

    CHECK(first.capacity() == second.capacity());
    CHECK(first.size() == first.size());
    CHECK(strcmp(first.c_str(), second.c_str()) == 0);
}
TEST_CASE("copy constructor test") {
    String first("test");
    String second(first);

    CHECK(first.capacity() == second.capacity());
    CHECK(first.size() == first.size());
    CHECK(strcmp(first.c_str(), second.c_str()) == 0);
}
TEST_CASE("empty and bool test") {
    String first;
    String second("test");
    String third("");

    CHECK(first.empty());
    CHECK(!bool(first));
    CHECK(!second.empty());
    CHECK(bool(second));
    CHECK(third.empty());
    CHECK(!third);
}
TEST_CASE("front and back test") {
    String first;
    String second("qwerty");

    CHECK(first.front() == first.back());
    CHECK(first.front() == '\0');
    CHECK(second.front() == 'q');
    CHECK(second.back() == 'y');

    second.front() = 'k';
    second.back() = 'i';

    CHECK(second.front() == 'k');
    CHECK(second.back() == 'i');
}
TEST_CASE("at and [] test") {
    String first("lorem ipsum");
    
    CHECK(first.at(3) == 'e');
    CHECK(first[2] == first.at(2));
    CHECK(first[first.capacity()] == first.back());
}
TEST_CASE("resize test") {
    String first("asdfghjkl");
    String second(first);
    second.resize(5);

    CHECK(second.capacity() == 6);
    CHECK(second.size() == 5);
    CHECK(strstr(first.c_str(), second.c_str()) != nullptr);
    CHECK(strstr(second.c_str(), first.c_str()) == nullptr);

    second = first;
    first.resize(100);

    CHECK(second.size() == first.size());
    CHECK(second.capacity() < first.capacity());
}
TEST_CASE("resize with character test") {
    String first("jaja");
    String second(first);
    first.resize(20, '!');

    CHECK(first[5] == '!');
    CHECK(first.back() == '!');
    CHECK(strstr(first.c_str(), second.c_str()) != nullptr);
}
TEST_CASE("shrink to fit test") {
    String first("rcs-2");
    String second(first);
    
    first.resize(60);
    first.shrink_to_fit();

    CHECK(strcmp(first.c_str(), second.c_str()) == 0);
    CHECK(first.capacity() == second.capacity());
}
TEST_CASE("push test") {
    String test("1000");

    test.push('k');
    test.push('j');
    test.push('\0');
    test.push('z');

    CHECK(strcmp("1000kj", test.c_str()) == 0);
}
TEST_CASE("append test") {
    String first("q");
    String second("qw");

    first.append("we").append("rty");
    second.append("ert").append("y");

    CHECK(strcmp(first.c_str(), "qwerty") == 0);
    CHECK(strcmp(second.c_str(), "qwerty") == 0);
}
TEST_CASE("+ test") {
    String first("qwe");
    String second("rty");
    String test = first + second;

    CHECK(strcmp("qwerty", test.c_str()) == 0);
}
TEST_CASE("+= test") {
    String first("qwe");
    String second("rty");
    second += first;

    CHECK(strcmp("rtyqwe", second.c_str()) == 0);
}
TEST_CASE("input test") {
    String test;
    test.resize(20);
    std::cout << "input a string \n";
    std::cin >> test;
    std::cout << test << '\n';
    CHECK(test.capacity() == 21);
    CHECK(test.size() <= 20);
    CHECK(strlen(test.c_str()) == test.size());
}
int main () {
    doctest::Context().run();
    return 0;
}