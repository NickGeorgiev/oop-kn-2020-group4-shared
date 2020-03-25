#include<iostream>
#include"String.h"
size_t String::length_of(const char* data) const {
    size_t i = 0;
    while( data[i] != 0 ){
        ++i;
    }
    return i;
}

void String::copy(const char* data) {
    size_t _size = length_of(data);
    
    str = new (std::nothrow) char[cap];

    for(int i = 0 ; i < _size ; ++i) {
        str[i] = data[i];
    }
    str[_size] = 0;
}

////

String::String() : str{nullptr} , cap{0} { }

String::String(const String& other) : cap{other.cap} {
    copy(other.str);
}

String::String(const char* data) {
    cap = 2*length_of(data);
    copy(data);
}

String& String::operator = (const String& other) {
    if(this != &other) {
        cap = other.cap;
        delete [] str;
        copy(other.str);
    }
}

String::~String() {
    delete [] str;
    cap = 0;
}

////

void String::resize(size_t n) {
    if(n == 0) {
        ++n; //space for 0
    }
    else {
        size_t _size = std::min(size(),n-1);
        char* new_buffer = new (std::nothrow) char[n];

        for(int i = 0 ; i < _size ; ++i) {
            new_buffer[i] = str[i];
        }
        new_buffer[_size] = 0;

        delete [] str;
        str = new_buffer;
        cap = n;
    }
}

void String::push(const char& c) {
    size_t _size = size();

    if(( _size + 2 ) > cap ) {
        resize(2*_size+1);
    }
    str[_size] = c;
    str[_size+1] = 0;
}

size_t String::size() const {
    if(cap == 0 || !str) {
        return 0;
    }
    return length_of(str);
}

size_t String::capacity() const {
    if(str) {
        return cap;
    }
    return 0;
}

bool String::empty() const {
    return size() == 0;
}

char& String::at(size_t pos) {
    if(pos < cap) {
        return str[pos];
    }
    else {
        std::cout << "Out of bounds!";
    }        
}


const char& String::at(size_t pos) const {
    if(pos < cap) {
        return str[pos];
    }
    else {
        std::cout << "Out of bounds!";
    }
}

char& String::front() {
    return at(0);
}

const char& String::front() const {
    return at(0);
}

char& String::back() {
    size_t _size = size();
    return at(_size-1);
}

const char& String::back() const {
    size_t _size = length_of(str);
    return at(_size-1);
}

String& String::append(const String& other) {
    size_t _size = size();
    size_t _other_size = other.size();

    if((_size + _other_size + 1) > cap) {
        resize((_size + _other_size)*2);
    }

    for(int i = 0 ; i < _other_size ; ++i) {
        str[i+_size] = other.str[i];
    }
    str[_size + _other_size] = 0;
}

char* String::c_str() {
    size_t _size = size();
    char* new_str = new (std::nothrow) char[_size+1];

    for(int i = 0 ; i < _size ; ++i) {
        new_str[i] = str[i];
    }
    new_str[_size] = 0;
    return new_str;
}

void String::shrink_to_fit() {
    size_t _size = size();
    resize(_size+1);
}

void String::resize(size_t n , const char& character) {
    size_t _size = size();
    resize(n);

    for(int i = _size ; i < cap-1 ; ++i) {
        str[i] = character;
    }
    str[cap-1] = 0;
}

String String::operator + (const String& other) {
    String res(*this);
    res.append(other);
    return res;
}


String& String::operator += (const String& other) {
    append(other);
    return *this;
}

char& String::operator[] (size_t i) {
    return at(i);
}

const char& String::operator[] (size_t i) const {
    return at(i);
}

String::operator bool () const { //it doesnt`let me define this as explicit outside of the class declaration
    return !empty();
}

std::ostream& operator << (std::ostream& out, const String& current) {
    if(current.str) {
        out << current.str;
        return out;
    }
}

std::istream& operator >> (std::istream& in, String& current) {
    size_t stat_cap;
    if(current.cap > 1000) {
        stat_cap = current.cap;
    }
    else{
        stat_cap = 1000;    //for smaller strings i don`t want to resize in advance
    }
    char input[stat_cap];
    in >> input;

    delete [] current.str;
    size_t _size = current.length_of(input);
    current.cap = 2*_size + 1;
    current.copy(input);

    return in;
}