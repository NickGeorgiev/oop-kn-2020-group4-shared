#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include<iostream>
#include<cstring>
#include "String.cpp"

TEST_CASE("Default Constructor")
{
    String a("abc");
    CHECK(a.getSize() == 3);
}

TEST_CASE("Copy Constructor")
{
    String a("abcde");
	String b(a);

	CHECK(b.getSize() == 5);
	
	CHECK(strcmp(b.c_str(),"abcde") == 0);

}

TEST_CASE("Assignment") 
{
	String a("Tests");
	String b("ab");
	String c;
	c = b = a;
	CHECK(strcmp(c.c_str(),"Tests") == 0);
	
}

TEST_CASE("Empty") 
{
	String a;
	String b("");

	CHECK(a.empty());
	CHECK(b.empty());
}

TEST_CASE("Front") 
{
	String a("Tests");
	CHECK(a.front() == 'T');
}

TEST_CASE("Back")
{
    String a("Tests");
	CHECK(a.back() == 's');
}

TEST_CASE("At")
{
    String a("Tests");
    CHECK(a.at(1) == 'e');
}

TEST_CASE("Size")
{
    String a("Test");
    CHECK(a.getSize() == 4);
}

TEST_CASE("Capacity")
{
    String a("Test");
    CHECK(a.getCapacity() == 5);
}


TEST_CASE("Append")
{
    String a("ab");
    
    CHECK(strcmp(a.c_str(),"ab") == 0);
}


TEST_CASE("c_str")
{
    String a("ccc");
    CHECK(strcmp(a.c_str(),"ccc") == 0);
}

TEST_CASE("Push")
{
	String a("aa");
	a.push('b');
	CHECK(a.getSize() == 3);
}

TEST_CASE("operator +")
{
    String a("aa");
    String b("bb");
    String c;
	c = a + b;
    CHECK(strcmp(c.c_str(),"aabb") == 0);
}

TEST_CASE("operator +=")
{
    String a("aa");
    String b("bb");
    a+=b;
    CHECK(strcmp(a.c_str(),"aabb") == 0 );
}

TEST_CASE("operator bool")
{
	String a("aa");
	CHECK((bool)a == 0);
}


int main() {
	doctest::Context().run();
}