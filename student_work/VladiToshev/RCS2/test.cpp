/*Vladimir Toshev Group 4 FN82019*/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include <cstring>
#include "String.cpp"

TEST_CASE("String")
{
    SUBCASE("Construction")
    {
        SUBCASE("Default construction")
        {
            String test_String;
            CHECK(test_String.size() == 0);
            CHECK(test_String.capacity() == 1);
        }
        SUBCASE("Construction with capacity")
        {
            String test_String(20);
            CHECK(test_String.size() == 0);
            CHECK(test_String.capacity() == 20);
        }
        SUBCASE("Construction with a given string")
        {
            String test_String("Test");
            CHECK(test_String.size() == 4);
            CHECK(test_String.capacity() == 8);
        }
        SUBCASE("Construction with given string and capacity")
        {
            String test_String("TestStr", 20);
            CHECK(test_String.size() == 7);
            CHECK(test_String.capacity() == 20);
        }
        SUBCASE("Copy constructor")
        {
            String test_String("Test", 15);
            String copy(test_String);

            CHECK(copy.size() == 4);
            CHECK(copy.capacity() == 15);
        }
    }

    SUBCASE("Destructor")
    {
        String test_String("Test", 15);
        test_String.~String();

        CHECK(test_String.size() == 0);
        CHECK(test_String.capacity() == 0);
    }

    SUBCASE("Operators")
    {
        SUBCASE("Operator =")
        {
            String test_String("Test", 15);
            String copy;
            copy = test_String;

            CHECK(copy.size() == 4);
            CHECK(copy.capacity() == 15);
        }
        SUBCASE("Operator +")
        {

            String first_String("Test", 15);
            String second_String("String", 10);
            second_String = second_String + first_String;
            CHECK(second_String.size() == 10);
            CHECK(second_String.capacity() == 20);
        }
        SUBCASE("Operator +=")
        {
            String first_String("Test", 5);
            String second_String("Value", 10);
            first_String += second_String;
            CHECK(first_String.size() == 9);
            CHECK(first_String.capacity() == 10);
        }
        SUBCASE("Operator []")
        {
            String test_String("TestStr", 20);
            CHECK(test_String[3] == 't');
            test_String[0] = 'K';
            CHECK(test_String[0] == 'K');
        }
        SUBCASE("Operator bool")
        {
            String test_String("TestStr", 20);
            String def_String;
            CHECK(bool(test_String) == 1);
            CHECK(bool(def_String) == 0);
        }
    }
    SUBCASE("Functions")
    {
        SUBCASE("Size")
        {
            String test_String("Test", 15);
            CHECK(test_String.size() == 4);
        }
        SUBCASE("Capacity")
        {

            String test_String("Test", 15);
            CHECK(test_String.capacity() == 15);
        }
        SUBCASE("Push")
        {

            String test_String("Test", 15);
            test_String.push('K');
            CHECK(test_String.back() == 'K');

            String test_More_Than_Cap("Test", 5);
            test_More_Than_Cap.push('Q');
            CHECK(test_More_Than_Cap.size() == 5);
            CHECK(test_More_Than_Cap.capacity() == 10);
            CHECK(test_More_Than_Cap.back() == 'Q');
        }
        SUBCASE("At")
        {
            String test_String("TestValue", 25);
            CHECK(test_String.at(3) == 't');
            test_String.at(4) = 'K';
            CHECK(test_String.at(4) == 'K');
        }
        SUBCASE("Front")
        {
            String test_String("TestStr", 20);
            CHECK(test_String.front() == 'T');
            test_String.front() = 'K';
            CHECK(test_String.front() == 'K');
        }
        SUBCASE("Back")
        {
            String test_String("TestStr", 20);
            CHECK(test_String.back() == 'r');
            test_String.back() = 'K';
            CHECK(test_String.back() == 'K');
        }
       SUBCASE("Append")
        {
            String first_String("Test", 10);
            String second_String("StringTest", 15);
            first_String.append(second_String);
            CHECK(first_String.size() == 14);
            CHECK(first_String.capacity() == 20);
        }
        SUBCASE("Char Array")
        {
            String test_String("TestStr", 10);
            char *charArray = new char[test_String.size() + 1];
            charArray = test_String.c_str();
            CHECK(strcmp(charArray, "TestStr") == 0);
            delete[] charArray;
        }
        SUBCASE("Shrink to fit")
        {
            String test_String("TestStr", 25);
            CHECK(test_String.size() == 7);
            CHECK(test_String.capacity() == 25);

            test_String.shrink_to_fit();

            CHECK(test_String.size() == 7);
            CHECK(test_String.capacity() == 8);
        }
        SUBCASE("Resize without push")
        {
            String test_String("TestStr", 25);
            test_String.resize(10);
            CHECK(test_String.size() == 7);
            CHECK(test_String.capacity() == 10);
        }
        SUBCASE("Resize with push")
        {
            String test_String("TestStr", 25);
            test_String.resize(15, 'Q');
            CHECK(test_String.size() == 14);
            CHECK(test_String.capacity() == 15);
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
