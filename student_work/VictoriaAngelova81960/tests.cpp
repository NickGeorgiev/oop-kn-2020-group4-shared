#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include<iostream>
#include<cstring>
#include<cassert>
#include "Sstring.h"


TEST_CASE("Construction") {
    SUBCASE("Default constructor") {
        String s1;

        CHECK(s1.size()==0);
        CHECK(s1.capacity()==1);
    }
    SUBCASE("With given capacity") {
        String s2(15);

        CHECK(s2.size()==0);
        CHECK(s2.capacity()==15);
    }
    SUBCASE("With given char array") {
        String s3("Hello");

        CHECK(s3.size()==5);
        CHECK(s3.capacity()==6);
    }
    SUBCASE("Copy constructor") {
        String s4("hi");
        String s5(s4);

        CHECK(s5.size()==2);
        CHECK(s5.capacity()==3);
    }
}

TEST_CASE("Member functions") {
    SUBCASE("At, Front, Back") {
        String s("abcd");

        CHECK(s.front()=='a');
        CHECK(s.back()=='d');
        CHECK(s.at(0)=='a');
        CHECK(s.at(1)=='b');
        CHECK(s.at(2)=='c');
        CHECK(s.at(3)=='d');

        s.at(2)='o';
        s.front()='s';
        s.back()='p';

        CHECK(s.at(0)=='s');
        CHECK(s.at(2)=='o');
        CHECK(s.at(3)=='p');

        const String s1("Hello");
        CHECK(s1.at(2)=='l');
        CHECK(s1.front()=='H');
        CHECK(s1.back()=='o');
        
    }
    SUBCASE("Push") {
        String s;
        s.push('a');
        s.push('b');

        CHECK(s.size()==2);
        CHECK(s.capacity()>2);

        s.push('c');
        s.push('d');

        CHECK (s.size()==4);
        CHECK(s.capacity()>4);
        CHECK(s.front()=='a');
        CHECK(s.at(1)=='b');
        CHECK(s[2]=='c');
        CHECK(s.back()=='d');
    }
    SUBCASE("Append") {
        String s1("abc");
        String s2("def");
        s1.append(s2);

        CHECK(s1.size()==6);
        CHECK(s1.capacity()>6);
        CHECK(s1.front()=='a');
        CHECK(s1.back()=='f');
    }
    SUBCASE("Empty") {
        String s1;
        String s2("");
        String s3("abc");

        CHECK(s1.empty());
        CHECK(s2.empty());
        CHECK(!(s3.empty()));
    }
    SUBCASE("C_str") {
        String s("new");
        char test[4]="new";
        CHECK(strcmp(test, s.c_str())==0);
    } 
    SUBCASE("Shrink to fit") {
        String s(100);
        s.push('u');
        s.push('v');
        s.push('w');

        CHECK(s.capacity()==100);

        s.shrink_to_fit();

        CHECK(s.capacity()==4);
    }
    SUBCASE("Resize") {
        String s("Hello world!");

        CHECK(s.size()==12);
        CHECK(s.capacity()==13);
        CHECK(s.at(5)==' ');

        s.resize(5);

        CHECK(s.size()==5);
        CHECK(strcmp("Hello", s.c_str())==0);

        String s1("aabb");
        s1.resize(10,'c');

        CHECK(s1.size()==10);
        CHECK(s1.at(9)=='c');
    }
} 

TEST_CASE("Operators") {
    SUBCASE("Operator = ") {
        String s1("new"); 
        String s2;
        s2=s1;

        CHECK(s1.size()==s2.size());
        CHECK(s1.capacity()==s2.capacity());

        s2.at(2)='o';
        s1.front()='k';

        CHECK(s1.at(2)=='w');
        CHECK(s2.front()=='n');
    }
    SUBCASE("Operator bool") {
        String s1;
        String s2("");
        String s3("abc");

        CHECK((bool)s1==1);
        CHECK((bool)s2==1);
        CHECK((bool)s3==0);
    }
    SUBCASE("Operator []") {
        String s("test");
        const String s1("TEST");

        CHECK(s[0]=='t');
        CHECK(s[3]=='t');
        CHECK(s1[0]=='T');
        CHECK(s1[3]=='T');

        s[2]='x';
        CHECK(s[2]=='x');
    }
    SUBCASE("Operator +=") {
        String s1("print");
        String s2(" text");
        s1+=s2;
        char test[11]="print text";

        CHECK(strcmp(test, s1.c_str())==0);
        CHECK(s1.size()==10);
        CHECK(s1.capacity()>10);
        CHECK(strcmp(" text", s2.c_str())==0); //проверявам дали += прави промени на s2
    }
    SUBCASE("Operator +") {
        String s1("print");
        String s2(" text");
        char test[11]="print text";

        CHECK(strcmp(test, (s1+s2).c_str())==0);
        CHECK((s1+s2).size()==10);
        CHECK((s1+s2).capacity()>10);
        CHECK(strcmp("print", s1.c_str())==0);
        CHECK(strcmp(" text", s2.c_str())==0);
    }
}

 
int main() {
    doctest::Context().run();

    return 0;
}