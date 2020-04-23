#define DOCTEST_CONFIG_IMPLEMENT
#include<iostream>
#include<cstring>
#include "String.h"
#include "doctest.h"
#include <sstream>

TEST_CASE("constuctor with arr"){
    String a("qwe");
    CHECK(strcmp(a.c_str(),"qwe")==0);
}
TEST_CASE("copycon"){
    String a("qwe");
    String b(a);
    CHECK(strcmp(b.c_str(),a.c_str())==0);
}
TEST_CASE("operator ="){
    String a("qwe");
    String b,c;
    c=b=a;
    CHECK(strcmp(b.c_str(),a.c_str())==0);
    CHECK(strcmp(c.c_str(),a.c_str())==0);
}
TEST_CASE("c_str"){
    String a("abc");
    CHECK(strcmp(a.c_str(),"abc")==0);
    CHECK(a[0]=='a');
    CHECK(a[1]=='b');
    CHECK(a[2]=='c');
}
TEST_CASE("append"){
    String a("abc");
    a.append("qwe");
    CHECK(strcmp(a.c_str(),"abcqwe")==0);
    CHECK(a[0]=='a');
    CHECK(a[1]=='b');
    CHECK(a[2]=='c');
    CHECK(a[3]=='q');
    CHECK(a[4]=='w');
    CHECK(a[5]=='e');
    //CHECK(a[6]=='\0'); //това гърми заради асърта във фунцкията at
}
TEST_CASE("push&&[]"){
    String a;
    a.push('t');
    a.push('a');
    CHECK(a[0]=='t');
    CHECK(a[1]=='a');
}
TEST_CASE("size"){
    String a("tab");
    CHECK(a.size()==3);
}
TEST_CASE("capacity"){
    String a("tabtabtab");
    CHECK(a.capacity()==16);
}
TEST_CASE("empty0"){
    String a;
    a.push('s');
    CHECK(a.empty()==0);
}
TEST_CASE("empty1"){
    String a;
    CHECK(a.empty()==1);
}
TEST_CASE("at"){
    String a("abcdef");
    CHECK(a.at(2)=='c');
    CHECK(a.at(5)=='f');
    a.at(2)='r';
    a.at(5)='s';
    CHECK(a.at(2)=='r');
    CHECK(a.at(5)=='s');
}
TEST_CASE("front"){
    String a("abcdef");
    CHECK(a.front()=='a');
    a.front()='t';
    CHECK(a.front()=='t');
}
TEST_CASE("back"){
    String a("abcdef");
    CHECK(a.back()=='f');
    a.back()='z';
    CHECK(a.back()=='z');
}
TEST_CASE("shrink to fit"){
    String a("abcd");
    a.shrink_to_fit();
    CHECK(a.capacity()==a.size()+1);
}
TEST_CASE("resize_smaller"){
    String a("abcedf");
    a.resize(3);
    CHECK(strcmp(a.c_str(),"abc")==0);   
}
TEST_CASE("resize_bigger"){
    String a("abc");
    a.resize(6,'t');
    CHECK(strcmp(a.c_str(),"abcttt")==0);   
}
TEST_CASE("operator +"){
    String a("abc");
    String b("qwe");
    CHECK(strcmp((a+b).c_str(),"abcqwe")==0);
}
TEST_CASE("operator +="){
    String a("abc");
    String b("qwe");
    String c=a+b;
    a+=b;
    CHECK(strcmp(a.c_str(),c.c_str())==0);
}
TEST_CASE("operator >>"){
    // String a;
    // std::cin>>a; // трябва да се въведе input
    // CHECK(strcmp(a.c_str(),"input")==0);
    std::istringstream in("input");
    String a("asd");
    in >> a;
    CHECK(strcmp(a.c_str(),"input")==0);
}
TEST_CASE("operator <<"){
    String a("output");
    std::stringstream out;
    out << a;
    CHECK(out.str()=="output");
}
TEST_CASE("operator bool"){
    String a("booltest");
    CHECK(bool(a)==0);
}

int main(){
    doctest::Context().run();
}