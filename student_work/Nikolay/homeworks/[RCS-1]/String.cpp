#include<iostream>
#include"String.h"
size_t String::length_of(const char* data) const {
    size_t i = 0;
    while( data[i] != 0 ){
        ++i;
    }
    return i;
}

void String::copy(const String& other) {
    _capacity = other._capacity;
    _size = other._size;
    
    str = new char[_capacity];

    for(int i = 0 ; i < _size ; ++i) {
        str[i] = other.str[i];
    }
    str[_size] = '\0';
}

////

String::String() : str{nullptr} , _capacity{0} , _size{0} { }

String::String(const String& other) {
    copy(other.str);
}

String::String(const char* data) {
    _size = length_of(data);
    _capacity = 2*_size;
    
    str = new char[_capacity];

    for(int i = 0 ; i < _size ; ++i) {
        str[i] = data[i];
    }
    str[_size] = 0;
}

String& String::operator = (const String& other) {
    
    if(this != &other) {
        delete [] str;
        copy(other.str);
    }
    return *this;
}

String::~String() {
    delete [] str;
    _capacity = 0;
    _size = 0;
}

////

void String::resize(const size_t& n) {
    _capacity = n;
    if (n < _size) {
        _size = n-1;
    }

    char* new_buffer = new char[n];

    for(int i = 0 ; i < _size ; ++i) {
        new_buffer[i] = str[i];
    }
    new_buffer[_size] = '\0';

    delete [] str;
    str = new_buffer;
    
    
}

void String::push(const char& c) {
    if(( _size + 2 ) > _capacity ) {
        resize(2*_size+1);
    }
    str[_size] = c;
    str[_size+1] = '\0';
    ++_size;
}

size_t String::size() const {
    return _size;
}

size_t String::capacity() const {
   return _capacity;
}

bool String::empty() const {
    return _size == 0;
}

char& String::at(const size_t& pos) {
    return str[pos];        
}

const char& String::at(const size_t& pos) const {
    return str[pos];
}

char& String::front() {
    return at(0);
}

const char& String::front() const {
    return at(0);
}

char& String::back() {
    return at(_size-1);
}

const char& String::back() const {
    return at(_size-1);
}

String& String::append(const String& other) {
    if((_size + other._size + 1) > _capacity) {
        resize((_size + other._size)*2);
    }

    for(int i = 0 ; i < other._size ; ++i) {
        str[i+_size] = other.str[i];
    }
    str[_size + other._size] = '\0';
    _size = _size + other._size;
}

char* String::c_str() {
    char* new_str = new char[_size+1];

    for(int i = 0 ; i < _size ; ++i) {
        new_str[i] = str[i];
    }
    new_str[_size] = 0;
    return new_str;
}

void String::shrink_to_fit() {
    resize(_size+1);
}

void String::resize(const size_t& n , const char& character) {
    resize(n);

    for(int i = _size ; i < _capacity-1 ; ++i) {
        str[i] = character;
    }
    str[_capacity-1] = '\0';
}

String String::operator + (const String& other) const{
    String res(*this);
    res.append(other);
    return res;
}


String& String::operator += (const String& other) {
    append(other);
    return *this;
}

char& String::operator[] (const size_t& i) {
    return at(i);
}

const char& String::operator[] (const size_t& i) const {
    return at(i);
}

String::operator bool () const {
    return !empty();
}

std::ostream& operator << (std::ostream& out, const String& current) {
    if(current.str) {
        out << current.str;
    }
    else {
        out << '\n';
    }
    return out;
}

std::istream& operator >> (std::istream& in, String& current) {
    current.resize(256);
    in >> current.str;
    current._size = current.length_of(current.str);
    current.shrink_to_fit();
    return in;
}