// create doctests
// test all

// upload to directory



#include <iostream>
#include <cstring>
#include <cassert>
#include "string.h"

void String::copy(const String& other){
    this->my_size = other.my_size;
    this->my_capacity = other.my_capacity;
    this->my_string = new char[my_capacity];
    strcpy(this->my_string, other.my_string);
}

void String::delete_str(){
    delete [] my_string;
    my_string = nullptr;
    my_size = 0;
    my_capacity = 0;
}

String::String() : my_string(nullptr), my_size(0), my_capacity(0) {}

String::String(const char* str, size_t str_capacity){
    
    assert(strlen(str) < str_capacity);

    my_size = strlen(str);
    my_capacity = str_capacity;
    my_string = new char[my_capacity];
    strcpy(my_string, str);
}

String::String (const String& other){
    copy(other);
}

String::~String(){
    delete_str();
}

void String::push(char c){
    if(my_size == my_capacity - 1){
        resize(my_capacity + 1);
    }
    my_string[my_size] = c;
    my_size++;
}

size_t String::size() const{
    return my_size;
}

size_t String::capacity() const{
    return my_capacity;
}

bool String::empty() const{
    return (my_size == 0);
}

char& String::at(int pos) const{
    return my_string[pos-1];
}

char& String::front() const{
    return my_string[0];
}

char& String::back() const{
    return my_string[my_size - 1];
}

void String::append(const String& str){
    strcat(this->my_string, str.my_string);
    this->my_size += str.my_size;
    this->my_capacity += str.my_capacity;
}

char* String::c_str() const{
    char *str = new char[my_size];
    strcpy(str, my_string);
    str[my_size] = 0;

    return str;
}

void String::shrink_to_fit(){
    if(my_capacity > my_size + 1){
        my_capacity = my_size + 1;
        resize(my_capacity);  
    }
}

void String::resize(size_t n){
    my_capacity = n;

    char *new_string = new char[my_capacity];
    strcpy(new_string, my_string);
    delete[] my_string;
    my_string = new_string;
    my_string[my_capacity - 1] = 0;
}

void String::resize(size_t n, char c){
    if(n > my_capacity){
        resize(n);
        for(int i = my_size; i < my_capacity-1; i++){
            my_string[i] = c;
        }
    }
}

String String::operator+= (const String& str){
    append(str);
    return *this;
}

String String::operator+ (const String& str){
    String result;

    result.my_size = this->my_size + str.my_size;
    result.my_capacity = this->my_capacity + str.my_capacity;
    int size_ = result.my_capacity;
    result.my_string = new char[size_];
    result.my_string = strcat(this->my_string, str.my_string);

    return result;
}

String String::operator= (const String& str){
    if(this != &str){
        delete_str();
        copy(str);
    }
    return *this;
}

char& String::operator[] (const int pos) const{
    return my_string[pos - 1];
}

String::operator bool() const {
    return (my_size == 0);
}

std::ostream& operator << (std::ostream& out, const String& str){
    out << str.my_string << " " << str.my_size << " " << str.my_capacity;
    return out;
}

std::istream& operator>> (std::istream& in, String& str){
    const size_t bufferSize = 1000;
    char buffer[bufferSize];
    in.get(buffer, bufferSize, '\n');


    str.my_size = strlen(buffer);
    str.my_capacity = strlen(buffer) + 1;
    str.my_string = new char[str.my_capacity];
    strcpy(str.my_string, buffer);

    return in;
}