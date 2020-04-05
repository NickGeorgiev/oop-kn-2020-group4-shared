#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include<iostream>
#include<cstring>
#include "string.cpp"

TEST_CASE ("Constructors test")
{
    SUBCASE("Testing default constructor")
    {
        String initialTest;

        CHECK(test.size() == 0);
        CHECK(test.capacity() == 0);
    }

    SUBCASE("Testing constructor with parameters")
    {
        String test("geburtstag",20);

        CHECK(test.size() == 10);
        CHECK(test.capacity() == 20);
        CHECK(strcmp(test.c_str(),"geburtstag") == 0);
    }

    SUBCASE("Testing copy constructor")
    {
        String test("geburtstag",20);
        String newtest(test);

        CHECK(strcmp(newtest.c_str(),test.c_str()) == 0);
        CHECK(newtest.size() == 10);
        CHECK(newtest.capacity() == 20);
    }
}

TEST_CASE("Methods test")
{
    SUBCASE("Testing push()")
    {
        String test("geburtstag",20);
        test.push('!');

        CHECK(test.size() == 11);
        CHECK(test.capacity() == 20);
        CHECK(test[10] == '!');
    }

    SUBCASE("Testing size()")
    {
        String test("geburtstag",20);

        CHECK(test.size() == 10);
    }

    SUBCASE("Testing capacity()")
    {
        String test("geburtstag",20);

        CHECK(test.capacity() == 20);
    }

    SUBCASE("Testing empty()")
    {
        String initialTest;
        String test("geburtstag",20);

        CHECK(initialTest.empty());
        CHECK(!test.empty());
    }

    SUBCASE("Testing at()")
    {
        String test("geburtstag",20);
        

        CHECK(test.at(4) == 'r');
       
    }

    SUBCASE("Testing front()")
    {
        String test("geburtstag",20);
        

        CHECK(test.front() == 'g');
        
    }

    SUBCASE("Testing back")
    {
        String test("geburtstag",20);
       
        CHECK(test.back() == 'g');
             
    }

    SUBCASE("Testing append()")
    {
        SUBCASE("capacity < size + secondSize")
        {
            String test("geburtstag",11), addTest("tragen",20);
            test.append(addTest);
            CHECK(test.size() == 16);
            CHECK(test.capacity() == 48);
            CHECK(strcmp(test.c_str(),"geburtstag tragen") == 0);
        }

        SUBCASE("capacity > size + secondSize")
        {   
            String test("geburtstag",20), addTest("tragen",15);
            test.append(addTest);
            CHECK(test.size() == 10);
            CHECK(test.capacity() == 20);
            CHECK(strcmp(test.c_str(),"geburtstag tragen") == 0);
        }
    }

    SUBCASE("Testing shrink_to_fit()")
    {
        String test("geburtstag",20);
        test.shrink_to_fit();

        CHECK(test.capacity() == 11);
    }

}

TEST_CASE("Operators test")
{
    SUBCASE("Operator =")
    {
        String test("geburtstag",20), addTest("tragen",15);
        test = addTest;

        CHECK(test.size() == 6);
        CHECK(test.capacity() == 15);
    }

    SUBCASE("Operator +")
    {
        String test("geburstag",20),addTest("tragen",15);
        test = test + addTest;

        CHECK(test.size() == 16);
        CHECK(test.capacity() == 30);

    }

    int main() {

	    doctest::Context().run();
        
    } 