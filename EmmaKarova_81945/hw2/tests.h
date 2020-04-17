#include "doctest.h"
#include <iostream>
#include <cstring>
#include "String.h"

TEST_CASE ("Creation test")
{
    SUBCASE("Default constructor")
    {
        String nothing;
        
        CHECK(nothing.size() == 0);
        CHECK(nothing.capacity() == 0);
    }

    SUBCASE("Constructor with parameters")
    {
        String name(10,"emma");
        
        CHECK(name.size() == 4);
        CHECK(name.capacity() == 10);
        CHECK(strcmp(name.c_str(),"emma") == 0);
    }

    SUBCASE("Copy constructor")
    {
        String name(10,"emma");
        String new_name(name);

        CHECK(strcmp(new_name.c_str(),name.c_str()) == 0);
        CHECK(new_name.size() == 4);
        CHECK(new_name.capacity() == 10);
    }
}

TEST_CASE("Member functions test")
{
    SUBCASE("Push function")
    {
        String name(10,"emma");
        name.push('s');

        CHECK(name.size() == 5);
        CHECK(name.capacity() == 10);
        CHECK(name[4] == 's');
    }

    SUBCASE("Empty function")
    {
        String nothing;
        String name(10,"emma");

        CHECK(nothing.empty());
        CHECK(!name.empty());
    }

    SUBCASE("At function")
    {
        String name(10,"emma");
        const String const_name(15,"Emma");

        CHECK(name.at(2) == 'm');
        CHECK(const_name.at(2) == 'm');
    }

    SUBCASE("Front function")
    {
        String name(10,"emma");
        const String const_name(15,"Emma");

        CHECK(name.front() == 'e');
        CHECK(const_name.front() == 'E');
    }

    SUBCASE("Back function")
    {
        String name(10,"emma");
        const String const_name(15,"Emma");

        CHECK(name.back() == 'a');
        CHECK(const_name.back() == 'a');        
    }

    SUBCASE("Append function")
    {
        SUBCASE("Not enough capacity")
        {
            String name(5,"emma"), sur(15,"karova");
            name.append(sur);
            CHECK(name.size() == 10);
            CHECK(name.capacity() == 11);
            CHECK(strcmp(name.c_str(),"emmakarova") == 0);
        }

        SUBCASE("Enough capacity")
        {   
            String name(20,"emma"), sur(15,"karova");
            name.append(sur);
            CHECK(name.size() == 10);
            CHECK(name.capacity() == 20);
            CHECK(strcmp(name.c_str(),"emmakarova") == 0);
        }
    }

    SUBCASE("Shrink_to_fit function")
    {
        String name(10,"emma");
        name.shrink_to_fit();

        CHECK(name.capacity() == 5);
    }

    SUBCASE("Resize function without character")
    {
        SUBCASE("n <= size")
        {
            String name(10,"emma");
            name.resize(3);
            CHECK(name.size() == 3);
            CHECK(name.capacity() == 10);
        }

        SUBCASE("size < n < capacity")
        {
            String name(10,"emma");
            name.resize(7);
            CHECK(name.size() == 7);
            CHECK(name.capacity() == 10);
        }

        SUBCASE("n > capacity")
        {
            String name(10,"emma");
            name.resize(12);
            CHECK(name.size() == 12);
            CHECK(name.capacity() == 13);
        }
    }

    SUBCASE("Resize function with character")
    {
        SUBCASE("n <= size")
        {
            String name(10,"emma");
            name.resize(3,'R');
            CHECK(name.size() == 3);
            CHECK(name.capacity() == 10);
        }

        SUBCASE("size < n <= capacity")
        {
            String name(10,"emma");
            name.resize(7,'R');
            CHECK(name.size() == 7);
            CHECK(name.capacity() == 10);
            CHECK(name[6] == 'R');
            CHECK(name[4] == 'R');
        }

        SUBCASE("n > capacity")
        {
            String name(10,"emma");
            name.resize(12,'R');
            
            CHECK(name.size() == 12);
            CHECK(name.capacity() == 13);
            CHECK(name[4] == 'R');
            CHECK(name[11] == 'R');
        }
    }
}

TEST_CASE("Operators test")
{
    SUBCASE("Operator =")
    {
        String name(10,"emma"), sur(15,"karova");
        name = sur;

        CHECK(name.size() == 6);
        CHECK(name.capacity() == 15);
    }

    SUBCASE("Operators + and +=")
    {
        String name(20,"emma"),sur(15,"karova");
        name += sur;

        CHECK(name.size() == 10);
        CHECK(name.capacity() == 20);

        String new_str;
        new_str = name + sur;

        CHECK(new_str.size() == 16);
        CHECK(new_str.capacity() == 20);
    }

    SUBCASE("Operators const [] and bool")
    {
        const String const_name(10,"Emma");

        CHECK(const_name[0] == 'E');
        CHECK(!const_name);
    }
}
