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
            //Given:
            String test_String;

            //Then:
            CHECK(test_String.c_str() == nullptr);
            CHECK(test_String.size() == 0);
            CHECK(test_String.capacity() == 1);
        }
        SUBCASE("Construction with capacity")
        {
            //Given:
            String test_String(20);

            //Then:
            CHECK(test_String.c_str() == nullptr);
            CHECK(test_String.size() == 0);
            CHECK(test_String.capacity() == 20);
        }
        SUBCASE("Construction with a given string")
        {
            //Given:
            String test_String("Test");

            //Then:
            CHECK(test_String.size() == 4);
            CHECK(test_String.capacity() == 8);

            //When:
            const char *charArray = test_String.c_str();

            //Then:
            CHECK(strcmp("Test", charArray) == 0);
            delete[] charArray;
        }
        SUBCASE("Construction with given string and capacity")
        {
            //Given:
            String test_String("TestStr", 20);

            //When:
            const char *charArray = test_String.c_str();

            //Then:
            CHECK(test_String.size() == 7);
            CHECK(test_String.capacity() == 20);
            CHECK(strcmp("TestStr", charArray) == 0);
            delete[] charArray;
        }
        SUBCASE("Copy constructor")
        {
            //Given:
            String test_String("Test", 15);
            String copy(test_String);

            //When:
            const char *charArray = test_String.c_str();

            //Then:
            CHECK(copy.size() == 4);
            CHECK(copy.capacity() == 15);
            CHECK(strcmp("Test", charArray) == 0);
            delete[] charArray;
        }
    }

    SUBCASE("Operators")
    {
        SUBCASE("Operator =")
        {
            //Given:
            String test_String("Test", 15);
            String copy;

            //When:
            copy = test_String;

            //Then:
            CHECK(copy.size() == 4);
            CHECK(copy.capacity() == 15);
        }
        SUBCASE("Operator +")
        {
            //Given:
            String first_String("Test", 15);
            String second_String("String", 10);
            second_String = second_String + first_String;

            //When:
            const char *charArray = second_String.c_str();

            //Then:
            CHECK(second_String.size() == 10);
            CHECK(second_String.capacity() == 11);
            CHECK(strcmp(charArray, "StringTest") == 0);
            delete[] charArray;
        }
        SUBCASE("Operator +=")
        {
            //Given:
            String first_String("Test", 5);
            String second_String("Value", 10);

            //When:
            first_String += second_String;
            const char *charArray = first_String.c_str();

            //Then:
            CHECK(first_String.size() == 9);
            CHECK(first_String.capacity() == 10);
            CHECK(strcmp(charArray, "TestValue") == 0);
            delete[] charArray;
        }
        SUBCASE("Operator []")
        {
            SUBCASE{"Operator [] access"}
            {
                //Given:
                String test_String("TestStr", 20);

                //Then:
                CHECK(test_String[3] == 't');
            }

            SUBCASE("Operator [] with change")
            { //Given:
                String test_String("TestStr", 20);

                //When:
                test_String[0] = 'K';

                //Then;
                CHECK(test_String[0] == 'K');
            }
        }
        SUBCASE("Operator bool")
        {
            //Given:
            String test_String("TestStr", 20);
            String def_String;

            //Then:
            CHECK(bool(test_String) == 1);
            CHECK(bool(def_String) == 0);
        }
    }
    SUBCASE("Functions")
    {
        SUBCASE("Size")
        {
            //Given:
            String test_String("Test", 15);

            //Then:
            CHECK(test_String.size() == 4);
        }
        SUBCASE("Capacity")
        {
            //Given:
            String test_String("Test", 15);

            //Then:
            CHECK(test_String.capacity() == 15);
        }
        SUBCASE("Push")
        {
            SUBCASE("Push without resize")
            {
                //Given:
                String test_String("Test", 15);

                //When:
                test_String.push('K');

                //Then:
                CHECK(test_String.back() == 'K');
                CHECK(test_String.size() == 4);
                CHECK(test_String.capacity() == 15);
            }

            SUBCASE("Push with resize")
            {
                //Given:
                String test_More_Than_Cap("Test", 5);

                //WHen:
                test_More_Than_Cap.push('Q');

                //Then:
                CHECK(test_More_Than_Cap.size() == 5);
                CHECK(test_More_Than_Cap.capacity() == 10);
                CHECK(test_More_Than_Cap.back() == 'Q');
            }
        }
        SUBCASE("At")
        {
            SUBCASE("At without change")
            {
                //Given:
                String test_String("TestValue", 25);

                //Then;
                CHECK(test_String.at(3) == 't');
            }

            SUBCASE{"At with change"}
            {
                //Given:
                String test_String("TestValue", 25);

                //When:
                test_String.at(4) = 'K';

                //Then;
                CHECK(test_String.at(4) == 'K');
            }
        }

        SUBCASE("Front")
        {
            SUBCASE("Front without change")
            {
                //Given:
                String test_String("TestValue", 25);

                //Then;
                CHECK(test_String.front() == 'T');
            }

            SUBCASE{"Front with change"}
            {
                //Given:
                String test_String("TestValue", 25);

                //When:
                test_String.front() = 'K';

                //Then;
                CHECK(test_String.front() == 'K');
            }
        }
        SUBCASE("Back")
        {
            SUBCASE("Front without change")
            {
                //Given:
                String test_String("TestValue", 25);

                //Then;
                CHECK(test_String.back() == 'e');
            }

            SUBCASE{"Front with change"}
            {
                //Given:
                String test_String("TestValue", 25);

                //When:
                test_String.back() = 'K';

                //Then;
                CHECK(test_String.back() == 'K');
            }
        }
        SUBCASE("Append")
        {
            //Given:
            String first_String("Test", 10);
            String second_String("StringTest", 15);

            //When:
            first_String.append(second_String);
            const char *charArray = first_String.c_str();

            //Then:
            CHECK(first_String.size() == 14);
            CHECK(first_String.capacity() == 15);
            CHECK(strcmp("TestStringTest", charArray) == 0);
            delete[] charArray;
        }
        SUBCASE("Char Array")
        {
            //Given:
            String test_String("TestStr", 10);

            //When:
            charArray = test_String.c_str();

            //Then:
            CHECK(strcmp(charArray, "TestStr") == 0);
            delete[] charArray;
        }
        SUBCASE("Shrink to fit")
        {
            //Given:
            String test_String("TestStr", 25);

            //Then:
            CHECK(test_String.size() == 7);
            CHECK(test_String.capacity() == 25);

            //When:
            test_String.shrink_to_fit();

            //Then;
            CHECK(test_String.size() == 7);
            CHECK(test_String.capacity() == 8);
        }
        SUBCASE("Resize without push")
        {
            //Given:
            String test_String("TestStr", 25);
            test_String.resize(10);

            //Then:
            CHECK(test_String.size() == 7);
            CHECK(test_String.capacity() == 10);
        }
        SUBCASE("Resize with push")
        {
            //Given:
            String test_String("TestStr", 25);
            test_String.resize(15, 'Q');

            //Then:
            CHECK(test_String.size() == 14);
            CHECK(test_String.capacity() == 15);
            CHECK(test_String.back() == 'Q');
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
