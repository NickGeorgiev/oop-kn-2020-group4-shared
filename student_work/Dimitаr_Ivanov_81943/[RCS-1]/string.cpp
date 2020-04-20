#include <iostream>
#include <cassert>
#include "string.h"
#include <cstring>

void String::copy(const String& other) {
    _capacity = other._capacity;
    _size = other._size;
    array = new (std::nothrow) char[_capacity];
    for (int i = 0; i < _size; i++) {
        array[i] = other.array[i];
    }
    array[_size] = '\0';
}
void String::delete_container() {
        delete [] array;
        _size = 0;
        _capacity = 0;
    }
void String::change_character (const char& answer, const size_t pos) {
    if (answer == 'y') {
        std::cout << "Enter character to replace with: ";
        char ch;
        array[pos] = ch;
    }
}

String::String () { 
    array = nullptr;
    _size = 0;
    _capacity = 0;
}
// String(const String& other): array(other.array), _size(other._size), _capacity(other._size) {}
String::String(const String& other) {
        copy(other);
}
String::String(const char* other) {
    _size = strlen(other);
    _capacity = 2*_size + 1;
    array = new char[_capacity];

    for (int i = 0; i < _size; i++) {
        array[i] = other[i];
    }
    array[_size] = '\0';
}
String& String::operator = (const String& other) {
    if(this != &other){
            delete_container();
            copy(other);
        }
        return *this;
}
String::~String(){
        delete_container();
    }

void String::push (const char& element) {
    if (_size + 2 > _capacity) {
        resize(_size);
    }
    array[_size] = element;
    array[_size+1] = '\0';
    ++_size;
}
size_t String::size() const{
    return _size;
}
size_t String::capacity () const {
    return _capacity;
}
bool String::empty () const {
    return _size == 0;
}
char& String::at (const size_t pos) {
    if (pos >= 0 && pos < _size) { // can be replaced with assert
        return array[pos];
    }
}
const char& String::at (const size_t pos) const {
    if (pos >= 0 && pos < _size) { // can be replaced with assert
        return array[pos];
    }
}
void String::at (const size_t pos, const char& answer) {
    if (pos >= 0 && pos < _size) { //  __||__
        change_character(answer,pos);
    }
}
char& String::front () {
    return array[0];
}
const char& String::front () const {
    return array[0];
}
void String::front (const char& answer) {
    change_character(answer,0);
}
char& String::back () {
    return array[_size - 1];
}
const char& String::back () const {
    return array[_size - 1];
}
void String::back (const char& answer) {
    change_character(answer, _size - 1);
}
void String::append (const String& str) {
    size_t old_size = _size;
    resize(_size + str._size);

    for (int i = 0; i < str._size; i++) {
        array[old_size + i] = str.array[i];
    }
}
char* String::c_str() {
    char * char_array = new char[_size + 1];

    for (int i = 0; i < _size; i++) {
        char_array[i] = array[i];
    }

    char_array[_size] = '\0';
    return char_array;
}
void String::shrink_to_fit() {
    _capacity = _size + 1;
}
void String::resize (const size_t& n) {
    _capacity = 2*n + 1;
    char* new_array = new char[_capacity];

    for (int i = 0; i < _size; i++) {
        new_array[i] = array[i];
    }

    _size = n;
    new_array[_size] = '\0';

    delete []array;
    array = new_array;
}
void String::resize (const size_t& n, const char& character) { // needs testing
    size_t old_size = _size;
    
    if (n > _size) {
        resize(n);
    }

    for (int i = old_size; i < n; i++) {
        array[i] = character;
    }
    _size = n;
    array[n] = '\0';
}

String String::operator + (const String& other) {
    String res(*this);
    res.append(other);
    return res;
}
String String::operator += (const String& other) {
    append(other);
    return *this;
}
char& String::operator [] (const size_t& i) {
    return array[i];
}
const char& String::operator [] (const size_t& i) const {
    return array[i];
}
String::operator bool () const {
    return empty();
}

std::istream& operator >> (std::istream& in, String& string) {
    in >> string.array;
    string._size = strlen(string.array);
    string._capacity = string._size + 1;
    return in;
}
std::ostream& operator << (std::ostream& stream, const String& string) {
    stream << string.array;
    return stream;
}