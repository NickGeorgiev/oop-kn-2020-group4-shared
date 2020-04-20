#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include <cstring>
#include "string.cpp"

TEST_CASE ("Default constuctor test") { //default constructor, size, capacity
    String str_1;

    CHECK(str_1.size() == 0);
    CHECK(str_1.capacity() == 0);
}
TEST_CASE ("Non-canon creation, copy and assignment constructor test") { //N-C creation, Copy constr. ,assignment constr.
    String str_1("Nameless");

    char* str = str_1.c_str();

    CHECK(strcmp(str,"Nameless") == 0);

    {
        String copy_str_1(str_1); 
        String copy_str_2;

        copy_str_2 = str_1;

        str = copy_str_1.c_str();
        CHECK (strcmp(str,"Nameless") == 0);

        str = copy_str_2.c_str();
        CHECK (strcmp(str,"Nameless") == 0);
    }

    CHECK (str_1.size() == 8);
    CHECK (str_1.capacity() == 17); //  2 * str_1.size + 1
}

TEST_CASE ("push test") {
    String str_1("Nameless");
    str_1.push('e');
    str_1.push('s');

    char* str = str_1.c_str();
    CHECK (strcmp(str,"Namelesses") == 0);

    CHECK (str_1.size() == 10);
    CHECK (str_1.capacity() == 17);
}
TEST_CASE ("empty test") {
    String str_1;
    
    CHECK (str_1.empty() == true);
}
TEST_CASE ("position methods test") { //at,front,back
    String str_1("Nameless");

    CHECK (str_1.at(3) == 'e');
    CHECK (str_1.front() == 'N');
    CHECK (str_1.back() == 's');

    // changing functionality

    str_1.at(2) = 'n';
    str_1.at(3) = 'a';
    str_1.front() = 'm';
    str_1.back() = 'e';

    char* str = str_1.c_str();

    CHECK(strcmp(str,"manalese") == 0);
}
TEST_CASE ("append test") {
    String str_1("Nameless");
    String str_2(" Dude");

    str_1.append(str_2);
    std::cout << str_1 << std::endl;
    std::cout << str_1.size() << std::endl;
    std::cout << str_1.capacity() << std::endl;

    char* str1 = str_1.c_str();
    CHECK(strcmp(str1,"Nameless Dude") == 0);
    CHECK(str_1.size() == 13);
    CHECK(str_1.capacity() == 27);
}
TEST_CASE ("string to char* test (c_str)") {
    String str_1("Name");

    char* str = str_1.c_str();
    CHECK (strcmp(str,"Name") == 0);
    CHECK (strlen(str) == str_1.size());
}
TEST_CASE ("shrinking capacity test") {
    String str_1("Nameless");

    str_1.shrink_to_fit();

    CHECK (str_1.capacity() == str_1.size() + 1);
}
TEST_CASE ("normal resize test") {
    String str_1("Nameless");
    str_1.resize(10);
    
    CHECK (str_1.size() == 10);
    CHECK (str_1.capacity() == 21);

    str_1.resize(4);

    char* str = str_1.c_str();
    CHECK (strcmp(str,"Name") == 0);
    CHECK (str_1.size() == 4);
    CHECK (str_1.capacity() == 9);
}
TEST_CASE ("resize with filling functionality") {
    String str_1("Name");
    str_1.resize(7,'s');

    char* str = str_1.c_str();
    CHECK (strcmp(str,"Namesss") == 0);
    CHECK (str_1.size() == 7);
    CHECK (str_1.capacity() == 15);
}

TEST_CASE ("operator +") {
    String str_1("Name");
    String str_2("less");

    String str_3 = str_1 + str_2;

    char* str = str_3.c_str();
    CHECK(strcmp(str,"Nameless") == 0);
    CHECK(strlen(str) == str_3.size());
    CHECK(str_3.size() == 8);
    CHECK(str_3.capacity() == 17);
}
TEST_CASE ("operator +=") {
    String str_1("Name");
    String str_2("less");

    str_1 += str_2;

    char* str = str_1.c_str();
    CHECK(strcmp(str,"Nameless") == 0);
    CHECK(strlen(str) == str_1.size());
    CHECK(str_1.size() == 8);
    CHECK(str_1.capacity() == 17);
}
TEST_CASE ("operator []") {
    String str_1("Nameless");

    CHECK(str_1[2] == 'm');

    str_1[0] = 'M';
    str_1[2] = 'n';

    char* str = str_1.c_str();
    CHECK(strcmp(str,"Maneless") == 0);
    CHECK(str_1[2] != 'm');
}
TEST_CASE ("operator bool") {
    String str_1;
    String str_2("Nameless");
    
    CHECK((bool)str_1);
    CHECK(!(bool)str_2);
}


int main()
{
    doctest::Context().run();
    return 0;
}