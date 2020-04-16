#include<iostream>
#include"LList.h"
#include"doctest.h"

TEST_CASE("ToEnd") {
	LList<int> l1;
	l1.toEnd(1);
	l1.toEnd(2);

	CHECK(l1.getElementAt(0) == 1);
	CHECK(l1.getElementAt(1) == 2);
	CHECK(l1.getSize() == 2);
}

TEST_CASE("Copying") {
	LList<int> l1;
	l1.toEnd(1);
	l1.toEnd(2);

	LList<int> l2(l1);

	CHECK(l2.getElementAt(0) == 1);
	CHECK(l2.getElementAt(1) == 2);
	CHECK(l2.getSize() == 2);
}

TEST_CASE("Assignement") {
	LList<int> l1;
	l1.toEnd(1);
	l1.toEnd(2);

	LList<int> l2;
	l2.toEnd(5);
	l2 = l1;

	CHECK(l2.getElementAt(0) == 1);
	CHECK(l2.getElementAt(1) == 2);
	CHECK(l2.getSize() == 2);
}

TEST_CASE("ToStart") {
	LList<int> l1;
	l1.toStart(2);
	l1.toStart(1);

	CHECK(l1.getElementAt(0) == 1);
	CHECK(l1.getElementAt(1) == 2);
	CHECK(l1.getSize() == 2);
}

TEST_CASE("InsertElemAt") {
	LList<int> l1;
	l1.insertElementAt(0,5);
	l1.insertElementAt(1,7);
	l1.insertElementAt(1,6);

	CHECK(l1.getElementAt(0) == 5);
	CHECK(l1.getElementAt(1) == 6);
	CHECK(l1.getElementAt(2) == 7);
	CHECK(l1.getSize() == 3);
}

TEST_CASE("Empty") {
	LList<int> l1;
	CHECK(l1.empty());
}

TEST_CASE("Reverse") {
	LList<int> l1;
	LList<int> l2;
	l1.toEnd(1);
	l1.toEnd(2);
	l1.toEnd(3);

	l1.reverse();
	l2.reverse();

	CHECK(l1.getElementAt(0) == 3);
	CHECK(l1.getElementAt(1) == 2);
	CHECK(l1.getElementAt(2) == 1);
	CHECK(l2.empty());
}

int main(){
	doctest::Context().run();
}