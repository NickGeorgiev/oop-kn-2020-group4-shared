#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "String.h"
#include "doctest.h"
#include <iostream>
#include <cstring>

TEST_CASE( "tes" ){
    String test("test22");
    CHECK(strcmp(test.c_str(), "test22") == 0);
}

//---------empty method-----------

TEST_CASE ("EMPTY")
{
    String str1;
    String str2("");

    CHECK(str1.empty());
    CHECK(str2.empty());
}

//---------push method--------------

TEST_CASE ("PUSH")
{
    String str1("push");
    str1.push('a');

    CHECK(str1.size() == 5);
    CHECK(str1.capacity() == 5);

}

//--------------front method---------------

TEST_CASE ("FRONT")
{
    const String str1("front");
    CHECK(str1.front_const() == 'f');

    String str2("t++");
    str2.front() = 'c';

    char* test = str2.c_str();

    CHECK(strcmp(test, "c++") == 0);

    delete[] test;

}

//-------------------back method-------------

TEST_CASE ("BACK")
{
    const String str1("back");
    CHECK(str1.back_const() == 'k');

    String str2("c+-");
    str2.back() = '+';

    char* test = str2.c_str();

    CHECK(strcmp(test, "c++") == 0);

    delete[] test;

}

//------------size method----------

TEST_CASE ("SIZE")
{
    const String str1("sizee");
    CHECK(str1.size() == 5);
}

//-----------cap method-----------

TEST_CASE ("CAPACITY")
{
    const String str1("capaa");
    CHECK(str1.capacity() == 6);
}

//---------at method-------------

TEST_CASE ("AT")
{
    const String str1("yeahh");
    CHECK(str1.at(2) == 'a');
}

//---------append method--------- 

TEST_CASE ("APPEND")
{
    String str1("Rainbow ");
    String str2("Six Siege");
    str1.append(str2);

    char* test = str1.c_str();
    CHECK(strcmp(test, "Rainbow Six Siege") == 0);
    delete[] test;
}

//---------shrink to fit---------

 TEST_CASE ("SHRINK")
{
    String str1("yeye");
    str1.shrink_to_fit();

    CHECK(str1.size() == 4);
    CHECK(str1.capacity() == 5);
}


//----------resize------------------

TEST_CASE ("RESIZE")
{
    String str1("test");
    str1.resize(6);

    CHECK(str1.size() == 6);
    CHECK(str1.capacity() == 7);
}

//--------resize2------------

TEST_CASE ("RESIZE2")
{
    String str1("cool");
    str1.resize2(10,'1');

    char* test = str1.c_str();
    CHECK(strcmp(test, "cool111111") == 0);
    delete[] test;
}


//--------operators------------

//-------- += -------------

TEST_CASE ("+=")
{
    String str1("God");
    String str2("damn");
    str1 += str2;

    String str3(" I'm ");
    String str4("good.");

    str3 += str4;

    str1 += str3;

    char* test = str1.c_str();
    CHECK(strcmp(test, "Goddamn I'm good.") == 0);
    delete[] test;
}

//----------- + --------------

TEST_CASE ("+")
{
    String str1("This thing ");
    String str2("works. ");
    String str3("I'm surprised.");

    str1 = str1 + str2 + str3;

    char* test = str1.c_str();
    CHECK(strcmp(test, "This thing works. I'm surprised.") == 0);
    delete[] test;
}

//-------------bool-----------

TEST_CASE("BOOL")
{
    String str1("");
    String str2("aa");

    CHECK(!(bool)str1);
    CHECK((bool)str2);
}

//-----------[]-----------------

TEST_CASE("[]")
{
    String str1("test");
    
    CHECK(str1[2] == 's');
}













