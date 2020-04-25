#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include<iostream>
#include<cstring>
#include "string.cpp"

TEST_CASE ("Constructors test")
{
    SUBCASE("Testing default constructor")
    {
        String test;

        CHECK(test.size() == 0);
        CHECK(test.capacity() == 0);
    }

    SUBCASE("Testing constructor with parameters")
    {
        String test("katze");

        CHECK(test.size() == 5);
        CHECK(test.capacity() == 15);
        CHECK(strcmp(test.c_str(),"katze") == 0);
    }

    SUBCASE("Testing copy constructor")
    {
        String test("katze");
        String newtest(test);

        CHECK(strcmp(newtest.c_str(),test.c_str()) == 0);
        CHECK(newtest.size() == 5);
        CHECK(newtest.capacity() == 15);
    }
}

TEST_CASE("Methods test")
{
    SUBCASE("Testing push()")
    {
        String test("kinder");
        test.push('!');

        CHECK(test.size() == 7);
        CHECK(test.capacity() == 18);
        CHECK(test[6] == '!');
    }

    SUBCASE("Testing size()")
    {
        String test("geschenk");

        CHECK(test.size() == 8);
    }

    SUBCASE("Testing capacity()")
    {
        String test("hund");

        CHECK(test.capacity() == 12);
    }

    SUBCASE("Testing empty()")
    {
        String initialTest;
        String test("geburtstag");

        CHECK(initialTest.empty());
        CHECK(!test.empty());
    }

    SUBCASE("Testing at()")
    {
        String test("schwimmen");
        

        CHECK(test.at(4) == 'i');
       
    }

    SUBCASE("Testing front()")
    {
        String test("gelesen");
        

        CHECK(test.front() == 'g');
        
    }

    SUBCASE("Testing back")
    {
        String test("sonntag");
       
        CHECK(test.back() == 'g');
             
    }

    SUBCASE("Testing append()")
    {
        SUBCASE("capacity < size + secondSize")
        {
            String test("hund"), addTest("geburtstag");
            test.append(addTest);
            CHECK(test.size() == 14);
            CHECK(test.capacity() == 42);
            CHECK(strcmp(test.c_str(),"hundgeburtstag") == 0);
        }

        SUBCASE("capacity > size + secondSize")
        {   
            String test("geburtstag"), addTest("hund");
            test.append(addTest);
            CHECK(test.size() == 14);
            CHECK(test.capacity() == 30);
            CHECK(strcmp(test.c_str(),"geburtstaghund") == 0);
        }
    }

    SUBCASE("Testing shrink_to_fit()")
    {
        String test("rot");
        test.shrink_to_fit();

        CHECK(test.capacity() == 4);
    }

}

TEST_CASE("Operators test")
{
    SUBCASE("Operator =")
    {
        String test("katze"), addTest("hund");
        test = addTest;

        CHECK(test.size() == 4);
        CHECK(test.capacity() == 12);
    }

    SUBCASE("Operator +")
    {
        String test("sonntag"),addTest("hund");
        test = test + addTest;

        CHECK(test.size() == 11);
        CHECK(test.capacity() == 21);

    }
}
    int main() {

	    doctest::Context().run();
        
    } 
