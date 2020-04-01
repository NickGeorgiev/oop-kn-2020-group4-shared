#include<iostream>
#include"String.h"
#include<cstring>

void String::copy_data(const char* data) {
    for(int i = 0 ; i < _size ; ++i) {
        str[i] = data[i];
    }
    str[_size] = '\0';
}

void String::copy_string(const String& other) {
    _capacity = other._capacity;
    _size = other._size;
    
    str = new char[_capacity];
    copy_data(other.str);
}

void String::change_capacity(const size_t& n) {
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

////

String::String() : str{nullptr} , _capacity{0} , _size{0} { }

String::String(const String& other) {
    copy_string(other.str);
}

String::String(const char* data) {
    _size = strlen(data);
    _capacity = 2*_size;
    
    str = new char[_capacity];

    copy_data(data);
}

String& String::operator = (const String& other) {
    if(this != &other) {
        delete [] str;
        copy_string(other.str);
    }
    return *this;
}

String::~String() {
    delete [] str;
    _capacity = 0;
    _size = 0;
}

////

void String::push(const char& c) {
    if(( _size + 2 ) > _capacity ) {
        change_capacity(2*(_size+1));
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
    if(pos < _size) {
        return str[pos];   
    }
}

const char& String::at(const size_t& pos) const {
    if(pos < _size) {
        return str[pos]; 
    }
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
        change_capacity((_size + other._size)*2);
    }

    for(int i = 0 ; i < other._size ; ++i) {
        str[i+_size] = other.str[i];
    }
    str[_size + other._size] = '\0';
    _size = _size + other._size;
}

char* String::c_str() const {
    char* new_str = new char[_size+1];

    for(int i = 0 ; i < _size ; ++i) {
        new_str[i] = str[i];
    }
    new_str[_size] = 0;
    return new_str;
}

void String::shrink_to_fit() {
    change_capacity(_size+1);
}

void String::resize(const size_t& n) {
    _capacity = 2*n;
    char* new_buffer = new char[_capacity];

    for(int i = 0 ; i < _size ; ++i) {
        new_buffer[i] = str[i];
    }
    _size = n;
    new_buffer[_size] = '\0';

    delete [] str;
    str = new_buffer;
}

void String::resize(const size_t& n , const char& character) {
    change_capacity(2*n);
    for(int i = _size ; i < n ; ++i) {
        str[i] = character;
    }
    _size = n;
    str[_size] = '\0';
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
    return str[i];
}

const char& String::operator[] (const size_t& i) const {
    return str[i];
}

String::operator bool () const {
    return !empty();
}

std::ostream& operator << (std::ostream& out, const String& current) {
    if(current.str) {
        out << current.str;
    }
    return out;
}

std::istream& operator >> (std::istream& in, String& current) {
    current.change_capacity(256);
    in >> current.str;
    current._size = strlen(current.str);
    current.change_capacity(2*current._size);
    return in;
}