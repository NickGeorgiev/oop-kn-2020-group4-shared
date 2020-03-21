#include <iostream>
#include <cstring>
#include <cassert>
#include "String.h"

// Constructors

    // private
String::String(const char* const str, const size_t size, const size_t capacity):
 _capacity{capacity}, _size{size}, data{new char[capacity]} {
    assert(size <= capacity);

    strcpy(data, str);
}
    // public
String::String(): String("", 0, 4) {}
String::String(const char* const str): String(str, strlen(str), strlen(str)) {}
String::String(const String& str): String(str.data, str._size, str._capacity) {}
String::~String() {
    delete[] data;
}

// Methods

size_t String::size() const {
    return _size;
}
size_t String::capacity() const {
    return _capacity;
}
char String::at(const int pos) const {
    assert(!empty() && pos >= 0 && pos < _size);
    return data[pos];
}
char String::front() const {
    assert(!empty());
    return data[0];
}
char String::back() const {
    assert(!empty());
    return data[_size - 1];
}
char* String::c_str() const {
    char* newString = new char[_capacity];
    strcpy(newString, data);
    return newString;
}
bool String::empty() const {
    return !(_size > 0);
}

void String::push(const char character) {
    if(_size + 1 > _capacity) {
        resize(_capacity*2);
    }
    data[_size] = character;
    ++_size;
} 
void String::append(const String& str) {
    for(size_t i = 0; i < str._size; i++) {
        push(str[i]);
    }
}

void String::shrink_to_fit() {
    resize(_size);
}
void String::resize(const size_t newCapacity) {
    _capacity = newCapacity;
    char* newContainer = new char[_capacity];

    strcpy(newContainer, data);
    delete[] data;
    data = newContainer;
}
void String::resize(const size_t newCapacity, const char filler) {
    resize(newCapacity);
    int difference = newCapacity - _size;
    for (size_t i = 0; i < difference; i++)
    {
        push(filler);
    }
}

// Operators

    void String::operator =(const String& str) {
    delete[] data;
    data = new char[str.capacity()];
    strcpy(data, str.c_str());
    _size = str.size();
    _capacity = str.capacity();
} 
String String::operator +(const String& toAppend) const {
    String str(*this);
    str += toAppend;
    return str;
}
String& String::operator +=(const String& toAppend) {
    append(toAppend);
    return (*this);
}
const char String::operator[](const int pos) const {
    return at(pos);
}
char& String::operator[](const int pos) {
    char* res = data + pos;
    return *res;
}

std::ostream& operator <<(std::ostream& out, const String& str) {
    out << str.data;
    return out;
}
std::istream& operator >>(std::istream& in, String& str) {
    in >> str.data;
    str._size = strlen(str.data);
    str._capacity = str._size;
}

String::operator bool() const {
    return !empty();
}