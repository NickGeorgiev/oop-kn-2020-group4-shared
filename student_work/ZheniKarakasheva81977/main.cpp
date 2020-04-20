#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include<iostream>
#include "LinkedList.cpp"

TEST_CASE ("Empty list")
{
    LList<int> emptyList;

    CHECK(emptyList.getSize() == 0);
    CHECK(emptyList.atStart() == nullptr);
    CHECK(emptyList.atEnd() == nullptr);

    SUBCASE("After doing reverse()") 
    {
        emptyList.reverse();

        CHECK(emptyList.getSize() == 0);
        CHECK(emptyList.atStart() == nullptr);
        CHECK(emptyList.atEnd() == nullptr);
    }

}

TEST_CASE("Testing toStart() + reverse()") 
{
    LList<int> blankList;

    CHECK(blankList.getSize() == 0);
    CHECK(blankList.atStart() == nullptr);
    CHECK(blankList.atEnd() == nullptr);

    blankList.toStart(5);
    blankList.toStart(25);
    blankList.toStart(45);
    blankList.toStart(60);
  
    CHECK(blankList.getSize() == 4);
    CHECK(blankList.atStart()->element == 60);
    CHECK(blankList.atEnd()->element == 5);

    blankList.reverse();

    CHECK(blankList.getSize() == 4);
    CHECK(blankList.atStart()->element == 5);
    CHECK(blankList.atEnd()->element == 60);   

}

TEST_CASE("checking toEnd() + reverse()") 
{
    LList<int> tempList;

    CHECK(tempList.getSize() == 0);
    CHECK(tempList.atStart() == nullptr);
    CHECK(tempList.atEnd() == nullptr);

    tempList.toEnd(10);
    tempList.toEnd(15);
    tempList.toEnd(20);
    tempList.toEnd(25);

    CHECK(tempList.getSize() == 4);
    CHECK(tempList.atStart()->element == 10);
    CHECK(tempList.atEnd()->element == 25);

    tempList.reverse();

    CHECK(tempList.atStart()->element == 25);
    CHECK(tempList.atEnd()->element == 10);

}

TEST_CASE("Checking at() + reverse()") 
{
    LList<int> randomList;
    LList<int> randomList2;
    
    CHECK(randomList.getSize() == 0);
    CHECK(randomList.atStart() == nullptr);
    CHECK(randomList.atEnd() == nullptr);

    CHECK(randomList2.getSize() == 0);
    CHECK(randomList2.atStart() == nullptr);
    CHECK(randomList2.atEnd() == nullptr);

    SUBCASE("Checking toStart() + at() + reverse()") 
    {
        randomList.toStart(29);
        randomList.toStart(15);
        randomList.toStart(17);
        randomList.toStart(38);

        CHECK(randomList.getSize() == 4);
        CHECK(randomList.at(0)->element == 38);
        CHECK(randomList.at(1)->element == 17);
        CHECK(randomList.at(2)->element == 15);
        CHECK(randomList.at(3)->element == 29);
   
        randomList.reverse();

        CHECK(randomList.getSize() == 4);
        CHECK(randomList.at(0)->element == 29);
        CHECK(randomList.at(1)->element == 15);
        CHECK(randomList.at(2)->element == 17);
        CHECK(randomList.at(3)->element == 38);
    }

    SUBCASE("Checking toEnd() + at() + reverse() "){
        randomList2.toEnd(3);
        randomList2.toEnd(5);
        randomList2.toEnd(7);
        randomList2.toEnd(9);
        randomList2.toEnd(11);

        CHECK(randomList2.getSize() == 5);
        CHECK(randomList2.at(0)->element == 3);
        CHECK(randomList2.at(1)->element == 5);
        CHECK(randomList2.at(2)->element == 7);
        CHECK(randomList2.at(3)->element == 9);
        CHECK(randomList2.at(4)->element == 11);

        randomList2.reverse();
        CHECK(randomList2.getSize() == 5);
        CHECK(randomList2.at(0)->element == 11);
        CHECK(randomList2.at(1)->element == 9);
        CHECK(randomList2.at(2)->element == 7);
        CHECK(randomList2.at(3)->element == 5);
        CHECK(randomList2.at(4)->element == 3);

    }
}

    int main() {

	    doctest::Context().run();
        
    } 