#include<iostream>
#include<cstring>
#include<cassert>
#include "Sstring.h"


void String::_resize () {
    _capacity *= 2;
    char* newStr = new char[_capacity];
    strcpy(newStr, str);
    delete [] str;
    str = newStr;
}

String::String () : String(1) {}
String::String (const size_t& capacity) : _capacity{capacity}, str{new char[capacity]}, _size{0} {}
String::String (const String& other) : _capacity{other._capacity}, _size{other._size}, str{new char[other._capacity]} {
    strcpy(str, other.str);
}

String& String::operator = (const String& other) {
    if(this!=&other) {
        delete [] str;
        _capacity=other._capacity;
        _size=other._size;
        str=new char[other._capacity];
        strcpy(str,other.str);
    }
    return *this;
}

String::~String () {
    delete [] str;
    str=nullptr;
    _size=0;
    _capacity=0;
}

String::String (const char* array) {
    _capacity=strlen(array)+1;
    _size=strlen(array);
    str=new char[_capacity];
    strcpy(str, array);
}

void String::push (const char& elem) {
   if((_capacity-_size)==1) {
        _resize();
    }
    str[_size]=elem;
    str[_size+1]=0;
    size++;
}

size_t String::size () const {
    return _size;
}

size_t String::capacity () const {
    return _capacity;
}

bool String::empty () const {
    return _size==0;
}

char& String::at (const size_t& pos) {
    assert(_size>0);
    assert(pos<_size);
    return str[pos];
}

char& String::front () {
    assert(_size>0);
    return str[0];
}

char& String::back () {
    assert(_size>0);
    return str[_size-1];
}

const char& String::at (const size_t& pos) const {
    assert(_size>0);
    assert(pos<_size);
    return str[pos];
}

const char& String::front () const {
    assert(_size>0);
    return str[0];
}

const char& String::back () const {
    assert(_size>0);
    return str[_size-1];
}

void String::append (const String& appStr) {
    while(_capacity<=_size+appStr._size) {
        _resize();
    }
    strcat(str, appStr.str);
    _size+=appStr._size;
    str[_size]=0;
}

const char* String::c_str () {
    char* charArray=new char[_size+1];
    strcpy(charArray, str);
    return charArray;
}

void String::shrink_to_fit () {
    if(strlen(str)>0) {
        _capacity=_size+1;
        char* newString=new char[_capacity];
        strcpy(newString, str);
        delete [] str;
        str=newString;
    }
}

void String::resize (const size_t& n) {
    if(n<_size) {
        _size=n;
        str[_size]=0;
    }
    else {
        while(_capacity<=n) {
            _resize();
        }
    }
}

void String::resize (const size_t& n, const char& character) {
    while(_capacity<=n) {
        _resize();
    }
    while(_size<n) {
        str[_size++]=character;
    }
    str[_size]=0;
}

char& String::operator [] (const size_t& pos) { 
    return str[pos];
}

const char& String::operator [] (const size_t& pos) const { 
    return str[pos];
}

String::operator bool () const {
    return empty();
}

String& String::operator += (const String& otherString) {
    append(otherString);
    return *this;
}

String String::operator + (const String& otherString) const {
    String result(*this);
    result+=otherString;
    return result;
}

std::ostream& operator << (std::ostream& out, const String& s) {
    out<<s.str;
    return out;
}

std::istream& operator >> (std::istream& in, String& s) {
    size_t i=0;
    char elem;
    in>>elem;
    while(elem!='\n' && elem!=' ') {
        s.str[i]=elem;
        elem=getchar();
        i++;
    }
    s.capacity=i+1; 
    s.size=i;
    s.str[s.size]=0;
    return in;
}
