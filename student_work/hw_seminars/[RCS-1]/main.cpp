#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <string.h>
#include "String.h"
#include "string.cpp"
#include "doctest.h"
TEST_CASE("String tests")
{
    SUBCASE("Constructors")
    {
        SUBCASE("string()")
        {
            string test;
            CHECK(test.get_text() == nullptr);
            CHECK(test.capacity() == 0);
            CHECK(test.get_size() == 0);
        }
        SUBCASE("char* constructor")
        {
            string test("Hello_world!");
            CHECK(strcmp(test.get_text(), "Hello_world!") == 0);
            CHECK(test.get_size() == 12);
            CHECK(test.capacity() == 13);
        }
        SUBCASE("copy constructor")
        {
            string test_1("Turtle"), test_2(test_1);
            CHECK(strcmp(test_1.get_text(), test_2.get_text()) == 0);
            CHECK(test_1.get_size() == test_2.get_size());
            CHECK(test_1.capacity() == test_2.capacity());
        }
    }
    SUBCASE("methods")
    {
        SUBCASE("push test")
        {
            string test("Uw");
            test.push('U');
            CHECK(strcmp(test.get_text(), "UwU") == 0);
            CHECK(test.get_size() == 3);
            CHECK(test.capacity() == 4);
        }
        SUBCASE("append test")
        {
            string test("Hello");
            test.append(" world!");
            CHECK(strcmp(test.get_text(), "Hello world!") == 0);
            CHECK(test.get_size() == 12);
            CHECK(test.capacity() == 13);
        }
        SUBCASE("test empty")
        {
            string test_1, test_2("Full");
            CHECK(test_1.empty() == 1);
            CHECK(test_2.empty() == 0);
        }
        SUBCASE("test at")
        {
            string test("java");
            CHECK(test.at(2) == 'v');
            test.at(2) = 'l';
            CHECK(test.at(2) == 'l');
        }
        SUBCASE("test front")
        {
            string test("Exalth");
            CHECK(test.front() == 'E');
            test.front() = 'I';
            CHECK(test.front() == 'I');
        }
        SUBCASE("test back")
        {
            string test("Exalth");
            CHECK(test.back() == 'h');
            test.back() = 'e';
            CHECK(test.back() == 'e');
        }
        SUBCASE("resize-exact size")
        {
            string test("I_am_23_characters_long");
            test.resize(25);
            CHECK(strcmp(test.get_text(), "I_am_23_characters_long") == 0);
            CHECK(test.get_size() == 25);
            CHECK(test.capacity() == 26);
            test.resize(4);
            CHECK(strcmp(test.get_text(), "I_am") == 0);
            CHECK(test.get_size() == 4);
            CHECK(test.capacity() == 26);
        }
        SUBCASE("resize-add characters")
        {
            string test("Goodbye");     //7
            char add_me[8] = " world!"; //7
            test.resize(16, add_me);
            CHECK(strcmp(test.get_text(), "Goodbye world!") == 0);
            CHECK(test.get_size() == 14);
            CHECK(test.capacity() == 17);
            test.resize(7, add_me);
            CHECK(strcmp(test.get_text(), "Goodbye") == 0);
            CHECK(test.get_size() == 7);
            CHECK(test.capacity() == 17);
        }
        SUBCASE("c_str-test")
        {
            string test("Hello");
            CHECK(strcmp(test.get_text(), test.c_str()) == 0);
        }
    }
    SUBCASE("operators")
    {
        SUBCASE("operator+")
        {
            string test("pad"), result;
            result = test + 'a';
            CHECK(strcmp(result.get_text(), "pada") == 0);
            result = test + "ame";
            CHECK(strcmp(result.get_text(), "padame") == 0);
        }
        SUBCASE("operator+=")
        {
            string test("pad");
            test += 'a';
            CHECK(strcmp(test.get_text(), "pada") == 0);
            test += "me";
            CHECK(strcmp(test.get_text(), "padame") == 0);
        }
        SUBCASE("operator[]")
        {
            string test("0123456789");
            CHECK(test[3] == '3');
            test[3] = 'a';
            CHECK(strcmp(test.get_text(), "012a456789") == 0);
            CHECK(test[3] == 'a');
        }
        SUBCASE("bool")
        {
            string test;
            CHECK(!test);
            test = "I am not empty";
            CHECK(test);
        }
    }
}
main()
{
    doctest::Context().run();
}
