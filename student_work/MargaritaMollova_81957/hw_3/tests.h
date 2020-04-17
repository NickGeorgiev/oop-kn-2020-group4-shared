#include "doctest.h"
#include "LList.h"

TEST_CASE ("Constructors")
{
    SUBCASE ("Defaul")
    {
        LList list;
        CHECK (list.getSize() == 0);
    }

    SUBCASE ("Copy")
    {
        LList list;
        list.toEnd(1);
        list.toEnd(2);
        list.toEnd(3);

        LList copyList(list);
        CHECK (copyList.getSize() == 3);
        CHECK (copyList[0] == 1);
        CHECK (copyList[2] == 3);
    }
}

TEST_CASE ("Operator =")
{
    LList list;
    list.toEnd(1);
    list.toEnd(2);
    list.toEnd(3);

    LList copyList;
    copyList = list;
    CHECK (copyList.getSize() == 3);
    CHECK (copyList[0] == 1);
    CHECK (copyList[2] == 3);
}

TEST_CASE ("Operator []")
{
    SUBCASE ("Constant")
    {
        LList list;
        list.toEnd(1);

        const LList constList(list);
        CHECK (constList[0] == 1);
    }

    SUBCASE ("Nonconstant")
    {
        LList list;
        list.toEnd(1);
        CHECK (list[0] == 1);
        CHECK (list.getSize() == 1);

        list[0] = 0;
        CHECK (list[0] == 0);
        CHECK (list.getSize() == 1);
    }
}

TEST_CASE ("At")
{
    LList list;
    list.toEnd(1);
    list.toEnd(2);
    list.toEnd(3);

    CHECK (list.at(0)->data == 1);
    CHECK (list.at(1)->data == 2);
    CHECK (list.at(2)->data == 3);
}

TEST_CASE ("To start")
{
    LList list;

    list.toStart(2);
    CHECK (list[0] == 2);
    CHECK (list.getSize() == 1);

    list.toStart(1);
    CHECK (list[0] == 1);
    CHECK (list[1] == 2);
    CHECK (list.getSize() == 2);
}

TEST_CASE ("To end")
{
    LList list;

    list.toEnd(1);
    CHECK (list[0] == 1);
    CHECK (list.at(0)->next == nullptr);
    CHECK (list.getSize() == 1);

    list.toEnd(2);
    CHECK (list[1] == 2);
    CHECK (list.at(1)->next == nullptr);
    CHECK (list.getSize() == 2);
}

TEST_CASE ("Insert at")
{
    LList list;
    list.toEnd(0);
    list.toEnd(3);

    list.insertAt(1, 2);
    CHECK (list[1] == 2);
    CHECK (list[2] == 3);
    CHECK (list.getSize() == 3);

    list.insertAt(1, 1);
    CHECK (list[1] == 1);
    CHECK (list[2] == 2);
    CHECK (list[3] == 3);
    CHECK (list.getSize() == 4);
}

TEST_CASE ("Delete start")
{
    LList list;
    list.toEnd(1);
    list.toEnd(2);

    list.deleteStart();
    CHECK (list[0] == 2);
    CHECK (list.getSize() == 1);

    list.deleteStart();
    CHECK (list.getSize() == 0);    
}

TEST_CASE ("Delete end")
{
    LList list;
    list.toEnd(1);
    list.toEnd(2);

    list.deleteEnd();
    CHECK (list.at(0)->next == nullptr);
    CHECK (list.getSize() == 1);

    list.deleteEnd();
    CHECK (list.getSize() == 0);
}

TEST_CASE ("Delete at")
{
    LList list;
    list.toEnd(1);
    list.toEnd(3);
    list.toEnd(2);

    list.deleteAt(1);
    CHECK (list[0] == 1);
    CHECK (list[1] == 2);
    CHECK (list.getSize() == 2);
}

TEST_CASE ("Reverse list")
{
    LList list;
    list.toEnd(1);
    list.toEnd(2);
    list.toEnd(3);
    list.toEnd(4);

    list.reverseList();
    CHECK (list.getSize() == 4);
    CHECK (list[0] == 4);
    CHECK (list[1] == 3);
    CHECK (list[2] == 2);
    CHECK (list[3] == 1);
    CHECK (list.at(3)->next == nullptr);
}