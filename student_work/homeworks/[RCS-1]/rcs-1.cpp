#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include <typeinfo>
#include "rcs-1.h"

TEST_CASE("String")
{
    SUBCASE("Constructors")
    {
        SUBCASE("Default")
        {
            String emptyStr;
            CHECK(emptyStr.capacity() == 0);
            CHECK(emptyStr.size() == 0);
            CHECK(emptyStr.getStr() == nullptr);
        }
        SUBCASE("By passing char array")
        {
            String charStr("Hello World");
            CHECK(charStr.capacity() == 12);
            CHECK(charStr.size() == 11);
            CHECK(strcmp(charStr.getStr(), "Hello World") == 0);
        }
        SUBCASE("Copy")
        {
            String charStr("Hello World");
            String copyStr(charStr);
            CHECK(copyStr.capacity() == 12);
            CHECK(copyStr.size() == 11);
            CHECK(strcmp(copyStr.getStr(), "Hello World") == 0);
        }
    }
    SUBCASE("Methods")
    {
        SUBCASE("Push")
        {
            String charStr("Hello World");
            charStr.push('y');
            CHECK(charStr.capacity() == 13);
            CHECK(charStr.size() == 12);
            CHECK(strcmp(charStr.getStr(), "Hello Worldy") == 0);
        }
        SUBCASE("Empty")
        {
            String emptyStr;
            String charStr("Hello World");
            CHECK(emptyStr.empty() == true);
            CHECK(charStr.empty() == false);
        }
        SUBCASE("At")
        {
            String charStr("Hello Worldy");
            CHECK(charStr.at(11) == 'y');
            charStr.at(11) = 'e';
            CHECK(charStr.at(11) == 'e');
        }
        SUBCASE("Front")
        {
            String charStr("Hello World");
            CHECK(charStr.front() == 'H');
            charStr.front() = 'Y';
            CHECK(charStr.front() == 'Y');
        }
        SUBCASE("Back")
        {
            String charStr("Hello World");
            CHECK(charStr.back() == 'd');
            charStr.back() = 't';
            CHECK(charStr.back() == 't');
        }
        SUBCASE("Append")
        {
            String firstStr("Hello ");
            String secondStr("World");
            firstStr.append(secondStr);
            CHECK(strcmp(firstStr.getStr(), "Hello World") == 0);
            CHECK(firstStr.capacity() == 12);
            CHECK(firstStr.size() == 11);
        }
        SUBCASE("Resize(const int&)")
        {
            String charStr("Hello World");
            charStr.resize(17);
            CHECK(charStr.size() == 17);
            CHECK(charStr.capacity() == 18);
            charStr.resize(5);
            CHECK(charStr.size() == 5);
            CHECK(charStr.capacity() == 18);
            CHECK(charStr.back() == 'o');
        }
        SUBCASE("Resize(const int&, char*)")
        {
            String charStr("Hello ");
            charStr.resize(11, "World");
            CHECK(charStr.capacity() == 12);
            CHECK(charStr.size() == 11);
            CHECK(strcmp(charStr.getStr(), "Hello World") == 0);
        }
        SUBCASE("C_str")
        {
            String charStr("Hello World");
            charStr.resize(17);
            CHECK(strcmp(charStr.c_str(), "Hello World") == 0);
            CHECK(strlen(charStr.c_str()) == 11);
            CHECK(typeid(charStr.c_str()) == typeid(const char *));         // ---------> is this proper syntax/should it be included
        }
        SUBCASE("Shrink_to_fit")
        {
            String charStr("Hello World");
            charStr.resize(17);
            charStr.shrink_to_fit();
            CHECK(charStr.capacity() == 12);
            CHECK(charStr.size() == 11);
            CHECK(strcmp(charStr.getStr(), "Hello World") == 0);
        }
    }
    SUBCASE("Operators")
    {
        SUBCASE("+")
        {
            String first("Is this technically");
            String second(" a concatenation?");
            String result = first + second;
            CHECK(result.capacity() == 37);
            CHECK(result.size() == 36);
            CHECK(strcmp(result.getStr(), "Is this technically a concatenation?") == 0);
        }
        SUBCASE("+=")
        {
            String first("Or is it ");
            String second("actually this?");
            first += second;
            CHECK(first.capacity() == 24);
            CHECK(first.size() == 23);
            CHECK(strcmp(first.getStr(), "Or is it actually this?") == 0);
        }
        SUBCASE("=")
        {
            String first("Please make this");
            String second("Equal to this");
            first = second;
            CHECK(first.capacity() == 14);
            CHECK(first.size() == 13);
            CHECK(strcmp(first.getStr(), "Equal to this") == 0);
        }
        SUBCASE("[]")
        {
            String charStr("Hello World");
            CHECK(charStr[4] == 'o');
            charStr[4] = 'a';
            CHECK(charStr[4] == 'a');
        }
        SUBCASE("bool")
        {
            String charStr("Hopefully I exist");
            String emptyStr;
            CHECK(bool(charStr) == true);
            CHECK(bool(emptyStr) == false);
        }
    }
}
int main()
{
    doctest::Context().run();
    return 0;
}