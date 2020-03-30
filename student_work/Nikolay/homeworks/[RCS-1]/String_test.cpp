#include<iostream>
#include<cstring>
#define DOCTEST_CONFIG_IMPLEMENT
#include"doctest.h"
#include"String.h"

TEST_CASE("Insertion") {
	String s1("Apple");
	CHECK(s1.size() == 5);
	CHECK(s1.capacity() == 10);
}
TEST_CASE("Return char-array") {
	String s1("Peach");
	char* str = s1.c_str();

	CHECK(str[2] == 'a');
	CHECK(str[5] == '\0');
	CHECK(strlen(str) == s1.size());
	delete [] str;
}
TEST_CASE("Index operator") {
	String s1("Apple");
	s1[1] = 'm';
	
	char* str = s1.c_str();
	CHECK(strcmp(str,"Ample") == 0);
	delete [] str;

	const String s2("Pear");

	str = s2.c_str();
	CHECK(strcmp(str,"Pear") == 0);
	delete [] str;
}
TEST_CASE("Copyconstructing") {
	String s1("Apple");
	String s2(s1);

	CHECK(s2.size() == 5);
	CHECK(s2.capacity() == 10);

	char* str = s2.c_str();
	CHECK(strcmp(str,"Apple") == 0);
	delete [] str;

	s1[0] = 'a';
	CHECK(s1[0] == 'a');
	CHECK(s2[0] == 'A');
}
TEST_CASE("Assignment") {
	String s1("Apple");
	String s2("Pear");
	String s3;
	s3 = s2 = s1;

	CHECK(s3.size() == 5);
	CHECK(s3.capacity() == 10);

	char* str = s3.c_str();
	CHECK(strcmp(str,"Apple") == 0);
	delete [] str;

	s1[0] = 'a';
	CHECK(s1[0] == 'a');
	CHECK(s2[0] == 'A');
}
TEST_CASE("Push") {
	String s1("Apple");
	s1.push('s');

	char* str = s1.c_str();
	CHECK(strcmp(str,"Apples") == 0);
	delete [] str;

	CHECK(s1.size() == 6);
	CHECK(s1.capacity() == 10);
}
TEST_CASE("Shrink to fit") {
	String s1("Apple");
	s1.shrink_to_fit();

	CHECK(s1.size() == 5);
	CHECK(s1.capacity() == 6);
}
TEST_CASE("Push more than capacity") {
	String s1("Apple");
	s1.shrink_to_fit();
	s1.push('s');

	char* str = s1.c_str();
	CHECK(strcmp(str,"Apples") == 0);
	delete [] str;

	CHECK(s1.size() == 6);
	CHECK(s1.capacity() == 12);
}
TEST_CASE("Empty") {
	String s1;
	String s2("");

	CHECK(s1.empty());
	CHECK(s2.empty());
}
TEST_CASE("At") {
	const String s1("Apple");
	CHECK(s1.at(1) == 'p');

	String s2("Apple");
	s2.at(1) = 'm';
	CHECK(s2.at(1) == 'm');
}
TEST_CASE("Front") {
	const String s1("Apple");
	CHECK(s1.front() == 'A');

	String s2("juice");
	s2.front() = 'J';
	CHECK(s2.front() == 'J');
}
TEST_CASE("Back") {
	const String s1("Apple");
	CHECK(s1.back() == 'e');

	String s2("juice");
	s2.back() = 'y';
	CHECK(s2.back() == 'y');
}
TEST_CASE("Append with enough capacity") {
	String s1("I like white ");
	String s2("Grapes");
	s1.append(s2);

	CHECK(s1.size() == 19);
	CHECK(s1.capacity() == 26);

	//checking if change to s2 affect s1
	s2[1] = 'n';
	s2[2] = 'o';
	s2[3] = 'm';

	char* str = s1.c_str();
	CHECK(strcmp(str,"I like white Grapes") == 0);
	delete [] str;

	str = s2.c_str();
	CHECK(strcmp(str,"Gnomes") == 0);
	delete [] str;
}
TEST_CASE("Append with change in capacity") {
	String s1("Blue");
	String s2("berries");
	s1.append(s2);

	CHECK(s1.size() == 11);
	CHECK(s1.capacity() == 22);

	char* str = s1.c_str();
	CHECK(strcmp(str,"Blueberries") == 0);
	delete [] str;
}
TEST_CASE("Append empty") {
	String s1("Peach");
	String s2;
	s1.append(s2);

	CHECK(s1.size() == 5);
	CHECK(s1.capacity() == 10);

	char* str = s1.c_str();
	CHECK(strcmp(str,"Peach") == 0);
	delete [] str;
}
TEST_CASE("Resize") {
	String s1("Apple");
	s1.resize(10);

	CHECK(s1.size() == 10);
	CHECK(s1.capacity() == 20);

	CHECK(s1[0] == 'A');
	CHECK(s1[4] == 'e');
	CHECK(s1[10] == '\0');

	String s2("Pear");
	s2.resize(2);

	CHECK(s2.size() == 2);
	CHECK(s2.capacity() == 4);

	CHECK(s2[0] == 'P');
	CHECK(s2[1] == 'e');
	CHECK(s2[2] == '\0');
}
TEST_CASE("Resize with fill") {
	String s1("Banana");
	s1.resize(8,'a');

	CHECK(s1.size() == 8);
	CHECK(s1.capacity() == 16);

	char* str = s1.c_str();
	CHECK(strcmp(str,"Bananaaa") == 0);
	delete [] str;
}
TEST_CASE("Operator +") {
	String s1("Milk");
	String s2("shake");
	String s3 = s1 + s2;
	
	char* str = s3.c_str();
	CHECK(strcmp(str,"Milkshake") == 0);
	delete [] str;

	//testing if s1 is modified
	CHECK(s1[4] == '\0');
	//i am not going to test with empty strings because this operator uses copyconstructing and append and they are already tested
}
TEST_CASE("Operator +=") {
	String s1("Milk");
	String s2("shake");
	s1 += s2;
	
	char* str = s1.c_str();
	CHECK(strcmp(str,"Milkshake") == 0);
	delete [] str;
	//i am not going to test with empty strings because this operator uses append and it is already tested
}
TEST_CASE("Operator bool") {
	String s1("Apricot");
	String s2;

	CHECK((bool)s1);
	CHECK(!(bool)s2);
}
int main() {
	doctest::Context().run();
}