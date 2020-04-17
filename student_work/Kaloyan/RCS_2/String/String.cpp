#ifndef _STR_CPP
#define _STR_CPP

#include <iostream>
#include <cstring>
#include "String.h"

void String::upsize(size_t n) {
    resize(limit + 3*n);
}

String::String(const char* str) {
    limit = strlen(str) + 1;
    length = strlen(str);

    content = new char [limit];
    strcpy(content, str);
}

String::String() : limit{1}, length{0} {
    content = new char[1];
    *content = '\0';
}
String::String(const String& other) : length{other.length}, limit{other.limit} {
    content = new char[limit];
    strncpy(content, other.content, other.length + 1);
}
String& String::operator = (const String& other) {
    length = other.length;
    limit = other.limit;
    delete [] content;
    content = new char[limit];
    strncpy(content, other.content, length);
    
    return *this;
}
String::~String() {
    delete [] content;
}

String& String::push(const char& element) {
    if(limit == 0 || length + 1 >= limit) {
        upsize(1);
    }
    content[length++] = element;
    content[length] = '\0';

    return *this;
}
size_t String::size () const {
    return length;
}
size_t String::capacity () const {
    return limit;
}
bool String::empty() const {
    return limit == 0 || length == 0 || content == nullptr;
}
char& String::at (const int& pos) {
    if (length == 0 || pos < 0) {
        return content[0];
    }
    else if (pos >= length){
        std::cout << "defaulted to last character\n";
        return back();
    }
    return content[pos];
}
char& String::front () {
    return content[0];
}
char& String::back () {
    if (length != 0) {
        return content[length - 1];
    }
    return content[0];
}
String& String::append (const char* str) {
    if (limit == 0 || length + strlen(str) >= limit) {
        upsize(strlen(str));
    }
    content[length] = '\0';
    strcat(content, str);
    length = strlen(content);

    return *this;
}
char* String::c_str () const {
    content[length] = '\0';
    return content;
}
String& String::shrink_to_fit () {
    resize(length);
}
String& String::resize(const size_t& n) {
    limit = n + 1;
    if (n <= length) {
        length = n;
        char* _content = new char [limit];
        strncpy(_content, content, length);
        delete [] content;
        content = _content;
    }
    else {
        content[length] = '\0';
        char* _content = new char [limit];
        strcpy(_content, content);
        delete [] content;
        content = _content;
    }

    return *this;
}
String& String::resize (const size_t& n, const char& character) {
    resize(n);
    if (length < limit-1) {
        for(int i = length; i <= limit - 2; i++) {
            content[i] = character;
        }
        length = limit - 1;
        content[length] = '\0';
    }
    return *this;
}

String String::operator + (const String& other) const{
    String temp(*this);
    temp += other;

    return temp;
}
String& String::operator += (const String& other) {
    limit += other.length;
    resize(limit - 1);
    append(other.content);
    
    return *this;
}
char& String::operator [] (const int pos) {
    return at(pos);
}
String::operator bool() {
    return !empty();
}

std::istream& operator >> (std::istream& in, String& string) {
    std::cout << "Warning! Takes no more than " << string.limit - 1 << " characters!\n";

    char* _content = new char[string.limit];
    in >> _content;
    strncpy(string.content, _content, string.limit - 1);
    delete [] _content;
    string.length = strlen(string.content);

    return in;
}
std::ostream& operator << (std::ostream& out, String& string) {
    out << string.c_str();

    return out;
}

#endif