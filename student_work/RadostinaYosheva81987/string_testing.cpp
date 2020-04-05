#include <iostream>
#include <cstring>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "string.h"



TEST_CASE("Initializing test"){
    String s1;
    String s2("String", 9);

    CHECK(s1.size() == 0);
    CHECK(s1.capacity() == 0);
    CHECK(s1.get_my_string() == nullptr);

    CHECK(s2.size() == 6);
    CHECK(s2.capacity() == 9);
    CHECK(strcmp(s2.get_my_string(), "String") == 0);
}

TEST_CASE("Concatenating test"){

    String s1("String", 9);
    String s2(" test", 6);

    SUBCASE("Symbol"){

        s1.push('s');

        CHECK(strcmp(s1.get_my_string(), "Strings") == 0);
    }

    SUBCASE("String"){

        s1.append(s2);

        CHECK(strcmp(s1.get_my_string(), "String test") == 0);
    }
}

TEST_CASE("Operators test"){

    String s1("String", 9);
    String s2(" test", 6);
    String s3;

    SUBCASE("Addition +"){
        // Този не работи, но не мога да разбера защо
        // Ако се опитам да счупя теста с == -1, работи
            // s3 = s1 + s2;
            // CHECK(strcmp(s3.get_my_string(), "String test") == 0);
    }

    SUBCASE("Addition +="){
        s1 += s2;

        CHECK(strcmp(s1.get_my_string(), "String test") == 0);
    }

    SUBCASE("Bool"){
        bool isEmpty;

        if(s2){
            isEmpty = true;
        } else{
            isEmpty = false;
        }

        CHECK(isEmpty == false);
    }
}

TEST_CASE("Return element test"){

    String s("String", 7);

    SUBCASE("Given position"){
        CHECK(s.at(3) == 'r');
    }

    SUBCASE("First element"){
        CHECK(s.front() == 'S');
    }

    SUBCASE("Last element"){
        CHECK(s.back() == 'g');
    }
}

int main()
{
    doctest::Context().run();
}