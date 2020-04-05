#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "String.h"
#include <string.h>

TEST_CASE ("Constructors")
{
    SUBCASE("Default construcor")
    {
        String empty_string;
        CHECK(empty_string._size == 0);
        CHECK(empty_string._capacity == 4);
    }
    SUBCASE("Constructor with given capacity")
    {
        String test_string(10);
        CHECK(test_string._size == 0);
        CHECK(test_string._capacity == 10);
    }
    SUBCASE("Copy constuctor")
    {
        String test_string(5);
        test_string.push('a');
        test_string.push('b');
        String copy_string (test_string);
        CHECK(strcmp(copy_string.str, test_string.str) == 0)
    }
    SUBCASE("Constructor from char array")
    {
        String test_string ("String");
        CHECK(stcmp(test_string, "String") == 0);
    }
}
TEST_CASE("Operators")
{
    SUBCASE ("Operator =")
    {
        String test_string;
        test_string = "test";
        CHECK(strcmp(test_string, "test") == 0);
        String other_string;
        other_string = test_string;
        CHECK(strcmp(test_string, other_string) == 0);

    }
    SUBCASE ("Operator bool")
    {
        String test_string;
        CHECK(if(test_string));
    }
    SUBCASE("operator[]")
    {
        String test_string;
        test_string = "test";
        CHECH(test_string[0] == 't');
    }
    SUBCASE("Operator +")
    {
        String test_string;
        test_string = "test";
        String other_string = "check";
        String result = test_string + other_string;
        CHECH(strcmp(result, "testcheck") == 0);
    }

}
TEST_CASE ("Methods")
{
    String test_string;
    test_string.push('a');
    test_string.push('b');
    CHECH(stcmp(test_string, "ab") == 0);

    String some_string = "ab";
    String other_string = "cd";
    some_string.append(other_string);
    CHECK(stcmp(some_string, "abcd") == 0);

    

}
