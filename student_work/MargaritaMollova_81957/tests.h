#include <cstring>

#include "doctest.h"
#include "String.h"

TEST_CASE ("Operator ==")
{
    String t1("mau"), t2("mau"), t3("bau");

    CHECK ((bool)(t1==t2));
    CHECK (!(t1==t3));
}

TEST_CASE ("Size, Capacity and C_str")
{
    String t1("mau");

    CHECK (t1.size() == 3);
    CHECK (t1.capacity() == 6);
    CHECK (!strcmp(t1.c_str(), "mau"));
}

TEST_CASE ("Constructors")
{
    SUBCASE ("Constuctor with parameters")
    {
        String t1("kotka");
        CHECK (!strcmp(t1.c_str(),"kotka"));
        CHECK (t1.size() == 5);
        CHECK (t1.capacity() == 10);
    }

    SUBCASE ("Copy constructor")
    {
        String t1("kotka"), t2(t1);
        CHECK ((bool)(t2 == t1));
        CHECK (t2.capacity() == 10);
    }

    SUBCASE ("Default constructor")
    {
        String t3;
        CHECK (t3.size() == 0);
    }
}

TEST_CASE ("Operator =")
{
    String t1("kotka");
    String t2;

    t2 = t1;
    CHECK ((bool)(t2 == t1));
}

TEST_CASE ("Append")
{
    String t1("ko");
    String t2("tka");
    String t3("kotka");

    t1.append(t2);
    CHECK ((bool)(t1 == t3));
}

TEST_CASE ("Operaror +")
{
    String t1("kotka");
    String t2("kotkata");
    String t3("ta");

    CHECK ((bool)(t1+t3 == t2));
}

TEST_CASE ("Operator +=")
{
    String t1("kotka");
    String t2("kotkata");
    String t3("ta");

    t1+=t3;
    CHECK ((bool)(t1 == t2));
}

TEST_CASE ("At, front, back and Operator []")
{
    SUBCASE ("Only accessing the elements")
    {
        String t1("kotka");

        CHECK (t1.at(2) == 't');
        CHECK (t1.front() == 'k');
        CHECK (t1.back() == 'a');
        CHECK (t1[1] == 'o');  
    }

    SUBCASE ("Changing the elements")
    {
        String t1("kotka");

        t1.at(2) = 'i';
        t1.front() = 'p';
        t1.back() = 'i';
        t1[1] = 'u';
        CHECK (!strcmp(t1.c_str(), "puiki"));
    }

    SUBCASE ("Constant string")
    {
        const String const_t2("kamila");

        CHECK (const_t2.at(2) == 'm');
        CHECK (const_t2.front() == 'k');
        CHECK (const_t2.back() == 'a');
        CHECK (const_t2[4] == 'l');
    }
}

TEST_CASE ("Push")
{
    String t1;
    t1.push('a');
    t1.push('b');
    t1.push('c');

    CHECK (t1.size() == 3);
    CHECK (t1[2] == 'c');
}

TEST_CASE ("Empty and Operator bool")
{
    SUBCASE ("When empty")
    {
        String t1;
        CHECK (t1.empty());
        CHECK (t1);
    }

    SUBCASE ("When full")
    {
        String t1;
        t1.push('a');
        CHECK (!t1.empty());
        CHECK (!t1);
    }
}

TEST_CASE ("Shrink to fit")
{
    String t1("kotka");
    t1.shrink_to_fit();

    CHECK (t1.size() == 5);
    CHECK (t1.capacity() == 6);
}

TEST_CASE ("Resize(n)")
{
    SUBCASE ("When n<=size")
    {
        String t1("kotkata");

        t1.resize(5);
        CHECK (t1.size() == 5);
        CHECK (t1[4] == 'a');
    }

    SUBCASE ("When n>size")
    {
        String t("kotkata");

        t.resize(10);
        CHECK (t.size() == 7);
        CHECK (t[4] == 'a');
        CHECK (t.capacity() == 14);
    }
}

TEST_CASE ("Resize(n, character)")
{
    SUBCASE ("When n<=size")
    {
        String t1("kotkata");

        t1.resize(4,'a');
        CHECK (t1.size() == 4);
        CHECK (t1[3] == 'k');
    }

    SUBCASE ("When n>size")
    {
        String t1("kotka");

        t1.resize(11,'i');
        CHECK (t1.size() == 11);
        CHECK (t1[10] == 'i');
        CHECK (t1.capacity() == 22);
    }
}