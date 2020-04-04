#ifndef DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "string.h"
#include <cstring>
#include "doctest.h"
TEST_CASE("String() test")
{
    String g;
    CHECK(g.get_array() == nullptr);
    CHECK(g.get_size() == 0);
    CHECK(g.get_capacity() == 0);
}
TEST_CASE("String(String&) and String(char*) test")
{
    char *array;
    array = new char[5];
    array[0] = 't';
    array[1] = 'e';
    array[2] = 's';
    array[3] = 't';
    array[4] = 0;
    String first(array);
    String second(first);
    CHECK(first[0] == 't');
    CHECK(first[1] == 'e');
    CHECK(first[2] == 's');
    CHECK(first[3] == 't');
    CHECK(first.get_size() == 4);
    CHECK(first.get_capacity() == 5);
    CHECK(second[0] == 't');
    CHECK(second[1] == 'e');
    CHECK(second[2] == 's');
    CHECK(second[3] == 't');
    CHECK(second.get_size() == 4);
    CHECK(second.get_capacity() == 5);
    delete[] array;
}
TEST_CASE("operator = test")
{
    char *array;
    array = new char[5];
    array[0] = 't';
    array[1] = 'e';
    array[2] = 's';
    array[3] = 't';
    array[4] = 0;
    String first(array);
    String second;
    second = first;
    CHECK(second[0] == 't');
    CHECK(second[1] == 'e');
    CHECK(second[2] == 's');
    CHECK(second[3] == 't');
    CHECK(second.get_size() == 4);
    CHECK(second.get_capacity() == 5);
    delete[] array;
}
TEST_CASE("copy_str test")
{
    char *array;
    array = new char[5];
    array[0] = 't';
    array[1] = 'e';
    array[2] = 's';
    array[3] = 't';
    array[4] = 0;
    String first;
    first.copy_str(array, strlen(array), strlen(array) + 1);
    CHECK(first[0] == 't');
    CHECK(first[1] == 'e');
    CHECK(first[2] == 's');
    CHECK(first[3] == 't');
    CHECK(first.get_size() == 4);
    CHECK(first.get_capacity() == 5);
    delete[] array;
}
TEST_CASE("push,at,front,back test")
{
    char *array;
    array = new char[5];
    array[0] = 't';
    array[1] = 'e';
    array[2] = 's';
    array[3] = 't';
    array[4] = 0;
    String first(array);
    char element = 'h';
    first.push(element);
    CHECK(first[4] == 'h');
    CHECK(first.front() == 't');
    CHECK(first.back() == 'h');
    for (int i = 0; i < 5; ++i)
    {
        CHECK(first.at(i) == first[i]);
    }
    delete[] array;
}
TEST_CASE("append test")
{
    char *array;
    array = new char[5];
    array[0] = 't';
    array[1] = 'e';
    array[2] = 's';
    array[3] = 't';
    array[4] = 0;
    String first(array);
    delete[] array;
    array = new char[4];
    array[0] = 'i';
    array[1] = 'n';
    array[2] = 'g';
    first.append(array);
    CHECK(first[4] == 'i');
    CHECK(first[5] == 'n');
    CHECK(first[6] == 'g');
    delete[] array;
}
TEST_CASE("operator +=,+,bool test")
{
    char *array;
    array = new char[5];
    array[0] = 't';
    array[1] = 'e';
    array[2] = 's';
    array[3] = 't';
    array[4] = 0;
    String first(array);
    delete[] array;
    array = new char[4];
    array[0] = 'i';
    array[1] = 'n';
    array[2] = 'g';
    CHECK(bool(first) == 0);
    String second(array);
    String third;
     CHECK(bool(third) == 1);
    String fourth;
    third=first+second;
    fourth=first+=second;
    CHECK(first[0] == 't');
    CHECK(first[1] == 'e');
    CHECK(first[2] == 's');
    CHECK(first[3] == 't');
    CHECK(first[4] == 'i');
    CHECK(first[5] == 'n');
    CHECK(first[6] == 'g');
    CHECK(third[0] == 't');
    CHECK(third[1] == 'e');
    CHECK(third[2] == 's');
    CHECK(third[3] == 't');
    CHECK(third[4] == 'i');
    CHECK(third[5] == 'n');
    CHECK(third[6] == 'g');
    CHECK(fourth[0] == 't');
    CHECK(fourth[1] == 'e');
    CHECK(fourth[2] == 's');
    CHECK(fourth[3] == 't');
    CHECK(fourth[4] == 'i');
    CHECK(fourth[5] == 'n');
    CHECK(fourth[6] == 'g');
    delete[] array;
}
TEST_CASE("resize,shrink_to_fit test")
{
    char *array;
    array = new char[5];
    array[0] = 't';
    array[1] = 'e';
    array[2] = 's';
    array[3] = 't';
    array[4] = 0;
    String first(array);
    delete[] array;
    array = new char[5];
    array[0] = 'i';
    array[1] = 'n';
    array[2] = 'g';
    array[3] = 'k';
    array[4] = 'l';
    first.resize(3);
 CHECK(first.get_size() == 2);
    CHECK(first.get_capacity() == 3);
    first.resize(8);
     CHECK(first.get_size() == 2);
    CHECK(first.get_capacity() == 8);
    first.shrink_to_fit();
     CHECK(first.get_size() == 2);
    CHECK(first.get_capacity() == 3);
    first.resize(6,array);
     CHECK(first[0] == 't');
    CHECK(first[1] == 'e');
     CHECK(first[2] == 'i');
    CHECK(first[3] == 'n');
    CHECK(first[4] == 'g');
     CHECK(first.get_size() == 5);
    CHECK(first.get_capacity() == 6);
    delete[] array;
}
#endif