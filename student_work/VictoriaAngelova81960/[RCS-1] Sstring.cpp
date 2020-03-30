#include<iostream>
#include<cstring>
#include<cassert>
#include "Sstring.h"

String::String () : str{nullptr}, size{0}, capacity{0} {}
String::String (const size_t& _capacity) : capacity{_capacity}, str{new char[_capacity]}, size{0} {}
String::String (const String& other) : capacity{other.capacity}, size{other.size}, str{new char[other.capacity]} {
    strcpy(str, other.str);
}

String& String::operator = (const String& other) {
    if(this!=&other) {
        delete [] str;
        capacity=other.capacity;
        size=other.size;
        str=new char[other.capacity];
        strcpy(str,other.str);
    }
    return *this;
}

String::~String () {
    delete [] str;
    str=nullptr;
    size=0;
    capacity=0;
}

String::String (const char* array) {
    capacity=(strlen(array)+1)*2;
    size=strlen(array);
    str=new char[capacity];
    strcpy(str, array);
    //ако не можем да използваме cstring
    /*for(int i=0;i<size;i++) {   
         str[i]=array[i];
     }*/
}

void String::push (char elem) {
    char* newString=new char[capacity+2];
    strcpy(newString, str);
    newString[size]=elem;
    newString[size+1]=0;
    size++;
    capacity+=2;

    delete []str;
    str=newString;
}

size_t String::_size () const {
    return size;
}

size_t String::_capacity () const {
    return capacity;
}

bool String::empty () const {
    return size==0;
}

char& String::at (const size_t& pos) {
    assert(size>0);
    return str[pos];
}

char& String::front () {
    assert(size>0);
    return str[0];
}

char& String::back () {
    assert(size>0);
    return str[size-1];
}

void String::append (const String& appStr) {
    capacity+=appStr.capacity;
    char* newString=new char[capacity];
    strcpy(newString, str);
    strcat(newString, appStr.str);
    size+=appStr.size;
    newString[size]=0;
    delete [] str;
    str=newString;
}

char* String::c_char () {
    char* charArray=new char[size+1];
    strcpy(charArray, str);
    return charArray;
}

void String::shrink_to_fit () {
    capacity=size+1;
    char* newString=new char[capacity+1];
    strcpy(newString, str);
    delete [] str;
    str=newString;
}

void String::resize (const size_t n) {
    capacity=n*2;
    char* smallerString=new char[capacity];
    size=n;
    for(size_t i=0;i<size;i++) {
        smallerString[i]=str[i];
    }
    smallerString[size]=0;
    delete []str;
    str=smallerString;
}

void String::resize (const size_t& n, char character) {
    capacity=n*2;
    char* biggerString=new char[capacity];
    strcpy(biggerString, str);
    while(size<=n) {
        size++;
        biggerString[size-1]=character;
    }
    biggerString[size]=0;
    delete [] str;
    str=biggerString;
}

char& String::operator [] (const size_t& pos) { 
    assert(pos<size);
    return str[pos];
}

String::operator bool () const {
    return size==0;
}

String& String::operator += (const String& otherString) {
    append(otherString);
    return *this;
}

String String::operator + (const String& otherString) const {
    String result(*this);
    result+=otherString;
    std::cout<<result<<std::endl;
    return result;
}

std::ostream& operator << (std::ostream& out, const String& s) {
    assert(s.capacity>=s.size);
    out<<s.str;
    return out;
}

std::istream& operator >> (std::istream& in, String& s) {
    std::cout<<"Capacity = ";
    in>>s.capacity;
    s.str=new char[s.capacity]; 
    in>>s.str;
    s.size=strlen(s.str);
    return in;
}
