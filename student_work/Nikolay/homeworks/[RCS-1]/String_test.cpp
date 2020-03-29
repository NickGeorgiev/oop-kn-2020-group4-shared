#include<iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include"doctest.h"
#include"String.h"

TEST_CASE("Insertion") {
	String s1("Apple");
	CHECK(s1.size() == 5);
	CHECK(s1.capacity() == 10);
}
TEST_CASE("Index operator") {
	String s1("Apple");
	s1[1] = 'm';

	CHECK(s1[0] == 'A');
	CHECK(s1[1] == 'm');
	CHECK(s1[2] == 'p');
	CHECK(s1[3] == 'l');
	CHECK(s1[4] == 'e');
	CHECK(s1[5] == '\0');

	const String s2("Pear");
	CHECK(s2[0] == 'P');
	CHECK(s2[1] == 'e');
	CHECK(s2[2] == 'a');
	CHECK(s2[3] == 'r');
	CHECK(s2[4] == '\0');
}
TEST_CASE("Copyconstructing") {
	String s1("Apple");
	String s2(s1);

	CHECK(s2[0] == 'A');
	CHECK(s2[1] == 'p');
	CHECK(s2[2] == 'p');
	CHECK(s2[3] == 'l');
	CHECK(s2[4] == 'e');
	CHECK(s2[5] == '\0');

	s1[0] = 'a';
	CHECK(s1[0] == 'a');
	CHECK(s2[0] == 'A');
}
TEST_CASE("Capacity and size after copyconstructing") {
	String s1("Apple");

	String s2(s1);
	CHECK(s2.size() == 5);
	CHECK(s2.capacity() == 10);
}
TEST_CASE("Assignment") {
	String s1("Apple");
	String s2("Pear");
	String s3;
	s3 = s2 = s1;

	CHECK(s3[0] == 'A');
	CHECK(s3[1] == 'p');
	CHECK(s3[2] == 'p');
	CHECK(s3[3] == 'l');
	CHECK(s3[4] == 'e');
	CHECK(s3[5] == '\0');

	s1[0] = 'a';
	CHECK(s1[0] == 'a');
	CHECK(s2[0] == 'A');
}
TEST_CASE("Capacity and size after assignment") {
	String s1("Apple");
	String s2("Pear");

	CHECK(s2.size() == 4);
	CHECK(s2.capacity() == 8);

	s2 = s1;

	CHECK(s2.size() == 5);
	CHECK(s2.capacity() == 10);
}
TEST_CASE("Resize") {
	String s1("Apple");
	s1.resize(15);

	CHECK(s1.size() == 5);
	CHECK(s1.capacity() == 15);

	CHECK(s1[0] == 'A');
	CHECK(s1[1] == 'p');
	CHECK(s1[2] == 'p');
	CHECK(s1[3] == 'l');
	CHECK(s1[4] == 'e');
	CHECK(s1[5] == '\0');

	String s2("Pear");
	s2.resize(3);

	CHECK(s2.size() == 2);
	CHECK(s2.capacity() == 3);

	CHECK(s2[0] == 'P');
	CHECK(s2[1] == 'e');
	CHECK(s2[2] == '\0');

}
TEST_CASE("Push") {
	String s1("Apple");
	s1.push('s');

	CHECK(s1[0] == 'A');
	CHECK(s1[1] == 'p');
	CHECK(s1[2] == 'p');
	CHECK(s1[3] == 'l');
	CHECK(s1[4] == 'e');
	CHECK(s1[5] == 's');
	CHECK(s1[6] == '\0');

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

	CHECK(s1[0] == 'A');
	CHECK(s1[1] == 'p');
	CHECK(s1[2] == 'p');
	CHECK(s1[3] == 'l');
	CHECK(s1[4] == 'e');
	CHECK(s1[5] == 's');
	CHECK(s1[6] == '\0');

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
	String s1("Apple");
	CHECK(s1.at(1) == 'p');
}
TEST_CASE("Front") {
	String s1("Apple");
	CHECK(s1.front() == 'A');
}
TEST_CASE("Back") {
	String s1("Apple");
	CHECK(s1.back() == 'e');
}
TEST_CASE("Append with enough size") {
	String s1("I like white ");
	String s2("Grapes");
	s1.append(s2);

	CHECK(s1.size() == 19);
	CHECK(s1.capacity() == 26);

	//checking if change to s2 affect s1
	s2[1] = 'n';
	s2[2] = 'o';
	s2[3] = 'm';

	CHECK(s1[0] == 'I');
	CHECK(s1[5] == 'e');
	CHECK(s1[10] == 't');
	CHECK(s1[15] == 'a');
	CHECK(s1[19] == '\0');

	CHECK(s2[0] == 'G');
	CHECK(s2[1] == 'n');
	CHECK(s2[2] == 'o');
	CHECK(s2[3] == 'm');
	CHECK(s2[4] == 'e');
	CHECK(s2[5] == 's');
	CHECK(s2[6] == '\0');
}
TEST_CASE("Append with resize") {
	String s1("Blue");
	String s2("berries");
	s1.append(s2);

	CHECK(s1.size() == 11);
	CHECK(s1.capacity() == 22);

	CHECK(s1[0] == 'B');
	CHECK(s1[2] == 'u');
	CHECK(s1[4] == 'b');
	CHECK(s1[6] == 'r');
	CHECK(s1[8] == 'i');
	CHECK(s1[10] == 's');
	CHECK(s1[11] == '\0');
}
TEST_CASE("Append to empty") {
	String s1;
	String s2("Grapes");
	s1.append(s2);

	CHECK(s1.size() == 6);
	CHECK(s1.capacity() == 12);

	CHECK(s1[0] == 'G');
	CHECK(s1[1] == 'r');
	CHECK(s1[2] == 'a');
	CHECK(s1[3] == 'p');
	CHECK(s1[4] == 'e');
	CHECK(s1[5] == 's');
	CHECK(s1[6] == '\0');
}
TEST_CASE("Append empty") {
	String s1("Peach");
	String s2;
	s1.append(s2);

	CHECK(s1.size() == 5);
	CHECK(s1.capacity() == 10);

	CHECK(s1[0] == 'P');
	CHECK(s1[1] == 'e');
	CHECK(s1[2] == 'a');
	CHECK(s1[3] == 'c');
	CHECK(s1[4] == 'h');
	CHECK(s1[5] == '\0');
}
TEST_CASE("Return char-array") {
	String s1("Peach");
	char* str = s1.c_str();

	CHECK(str[0] == 'P');
	CHECK(str[1] == 'e');
	CHECK(str[2] == 'a');
	CHECK(str[3] == 'c');
	CHECK(str[4] == 'h');
	CHECK(str[5] == '\0');
	delete [] str;
}
TEST_CASE("Resize with fill") {
	String s1("Banana");
	s1.resize(12,'a');

	CHECK(s1.size() == 11);
	CHECK(s1.capacity() == 12);

	for(int i = 5 ; i < 11 ; ++i) {
		CHECK(s1[i] == 'a');
	}
}
TEST_CASE("Operator +") {
	String s1("Milk");
	String s2("shake");
	String s3 = s1 + s2;
	
	CHECK(s3[0] == 'M');
	CHECK(s3[1] == 'i');
	CHECK(s3[2] == 'l');
	CHECK(s3[3] == 'k');
	CHECK(s3[4] == 's');
	CHECK(s3[5] == 'h');
	CHECK(s3[6] == 'a');
	CHECK(s3[7] == 'k');
	CHECK(s3[8] == 'e');
	CHECK(s3[9] == '\0');

	//testing if s1 is modified
	CHECK(s1[4] == '\0');
	//i am not going to test with empty strings because this operator uses copyconstructing and append and they are already tested
}
TEST_CASE("Operator +=") {
	String s1("Milk");
	String s2("shake");
	s1 += s2;
	
	CHECK(s1[0] == 'M');
	CHECK(s1[1] == 'i');
	CHECK(s1[2] == 'l');
	CHECK(s1[3] == 'k');
	CHECK(s1[4] == 's');
	CHECK(s1[5] == 'h');
	CHECK(s1[6] == 'a');
	CHECK(s1[7] == 'k');
	CHECK(s1[8] == 'e');
	CHECK(s1[9] == '\0');
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